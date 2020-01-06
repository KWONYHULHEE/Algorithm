#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, k;
string arr[60];
bool check[30];
int result;


/*
몇개의 단어를 배울 수 있는지 의 최댓값.
*/


void solve(int num) {

	//k개를 다 배운경우
	if (num == k) {

		int temp = 0;
		for (int i = 0; i < n; i++) {
			bool flag = true;

			for (int j = 0; j < arr[i].size(); j++) {
				if (!check[arr[i][j]-'a']) {
					flag = false;
					break;
				}
				if (flag) 
					temp++;
				
			}
			result = max(temp, result);
			return;
		}
	}

	else {
		for (int i = 0; i < 26; i++) {
			if (!check[i]) {
				check[i] = true;
				solve(num + 1);
				check[i] = false;
			}
		 }
	}

}
int main() {



	cin >> n >> k;

	if (k < 5) {
		cout << 0 << endl;
		return 0;
	}
	if (k == 26) {
		cout << n << endl;
		return 0;
	}

	k -= 5;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		arr[i] = arr[i].substr(4, arr[i].length()); //anta

		for (int j = 0; j < 4; j++)
			arr[i].pop_back();  //tica
			
	}

	check['a' - 'a'] = true;
	check['c' - 'a'] = true;
	check['i' - 'a'] = true;
	check['n' - 'a'] = true;
	check['t' - 'a'] = true;

	solve(0);

	cout << result;

	return 0;
}