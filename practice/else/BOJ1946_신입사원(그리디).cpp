#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int,int>> v;

int main() {
	int tc;
	int n;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int res = 1;
		v.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;

			v.push_back({ a,b });
		}

		sort(v.begin(), v.end());
		int grade = v[0].second;

		for (int i = 1; i < n; i++) {
			if (grade > v[i].second) {
				grade = v[i].second;
				res++;
			}
		}

		cout << res << "\n";

	}



	return 0;
}