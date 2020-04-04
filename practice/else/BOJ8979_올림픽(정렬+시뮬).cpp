#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Medal {
	int num;
	int gold;
	int silver;
	int bronze;
};
vector <Medal> medal;
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
int main() {

	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		medal.push_back({ a,b,c,d });

	}
	sort(medal.begin(), medal.end() , cmp);

	int rank = 1;
	Medal prev = medal[0];
	int res = 0;

	for (int i = 0; i < medal.size(); i++) {

		if (medal[i].gold != prev.gold || medal[i].silver != prev.silver
			|| medal[i].bronze != prev.bronze) {
			rank = i + 1;
		}

		prev.gold = medal[i].gold;
		prev.silver = medal[i].silver;
		prev.bronze = medal[i].bronze;

		if (k == medal[i].num) {
			res = rank;
			break;
		}

	}

	cout << res;

	return 0;
}