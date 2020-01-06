#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int n;
int arr[30];
vector <string> str;

bool cmp(int a, int b) {

	if (a > b) return true;
	else return false;

}

int main() {


	cin >> n;

	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		str.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		int pow = 1;
		string s = str[i];

		for (int j = s.length() - 1; j >= 0; j--)
		{
			int temp = s[j] - 'A';
			arr[temp] = arr[temp] + pow;
			pow = pow * 10;
		}
	}
	sort(arr, arr + 26, cmp);

	int ans = 0;
	int number = 9;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == 0) break;
		ans = ans + (arr[i] * number);
		number--;
	}

	cout << ans << endl;

	return 0;
}