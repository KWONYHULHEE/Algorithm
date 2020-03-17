#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string arr[10010];

int main() {
	int tc;
	int n;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for (int i = 1; i < n; i++) {
			if (arr[i].substr(0, arr[i - 1].size()) == arr[i - 1]) {
				flag = false;
				break;
			}
		}
		if (!flag) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
	
}