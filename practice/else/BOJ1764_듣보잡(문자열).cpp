#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
set <string> s;
set <string> s2;

int main() {
		
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		s.insert(temp);
	}
	int len = s.size();
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;

		s.insert(temp);

		if (s.size() == len) {
			cnt++;
			s2.insert(temp);
		}
		else {
			len = s.size();
		}
	}

	cout << cnt << "\n";

	for (auto i : s2) {
		cout << i << "\n";
	}

	return 0;
}