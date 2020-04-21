#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string arr[1010];
bool cmp(string a, string b) {
	string ab = a + b;
	string ba = b + a;
	return ab > ba;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int n;
	cin >> n;
	bool flag = false;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] != "0") flag = true;
	}

	if (!flag) cout << 0;
	else {
		sort(arr, arr + n, cmp);
		for (int i = 0; i < n; i++) {
			cout << arr[i];
		}
	}
	return 0;
}