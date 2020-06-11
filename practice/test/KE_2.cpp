#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Info {

	int win;
	int lose;
	int winset;
	int loseset;
};

map <string, Info> m;
vector <pair<pair<int, string>, int>> res;

bool cmp(pair<pair<int, string>, int> a, pair<pair<int, string>, int> b) {

	if (a.first.first >= b.first.first) {
		if (a.second > b.second) {
			return true;
		}
		return false;
	}
}
int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n*(n - 1); i++) {
		string a, c;
		int b, d;
		cin >> a >> b >> c >> d;
		if (b > d) {
			m[a].win++;
			m[c].lose++;
		}
		else if (b < d) {
			m[c].win++;
			m[a].lose++;
		}
		m[a].winset += b;
		m[a].loseset += d;
		m[c].loseset += b;
		m[c].winset += d;
	}


	for (auto it : m) {
		res.push_back({ {m[it.first].win,it.first},m[it.first].winset - m[it.first].loseset });
	}

	sort(res.begin(), res.end(), cmp);
	for (auto it : res) {
		cout << it.first.second << " " << it.first.first << " " << it.second << "\n";
	}

	return 0;
}