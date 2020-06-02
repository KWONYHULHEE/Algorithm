#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct Medal {
	int nation;
	int gold;
	int silver;
	int bronze;
};
vector <Medal> v;
int n, k;

bool cmp(Medal x, Medal y) {
	if (x.gold >= y.gold) {
		if (x.gold == y.gold) {
			if (x.silver >= y.silver) {
				if (x.silver == y.silver) {
					if (x.bronze > y.bronze) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({ a,b,c,d });
	}

	sort(v.begin(), v.end(), cmp);

	Medal prev = v[0];
	int res = 0;
	int rank = 1;

	for (int i = 0; i < n; i++) {
		if (v[i].gold != prev.gold || v[i].silver != prev.silver
			|| v[i].bronze != prev.bronze)
			rank = i + 1;

		prev.gold = v[i].gold;
		prev.silver = v[i].silver;
		prev.bronze = v[i].bronze;

		if (k == v[i].nation) {
			res = rank;
			break;
		}
	}
	cout << res;
	return 0;

}

