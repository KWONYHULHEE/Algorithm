#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


vector <pair<int, int>>v;
bool check[110];
bool flag = false;
int ex, ey;

int distance(pair<int, int> s1, pair<int, int> s2) {
	return abs(s1.first - s2.first) + abs(s1.second - s2.second);
}

void dfs(int x, int y) {


	if (distance({ex,ey}, {x,y}) <= 1000) {
		flag = true;
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (check[i]) continue;

		int a = v[i].first;
		int b = v[i].second;

		if (distance({ x,y }, { a,b }) <= 1000) {
			check[i] = true;
			dfs(a, b);
		}
		
	}

}
int main() {

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		ex = 0; ey = 0;
		v.clear();
		memset(check, false,sizeof(check));
		int n;
		cin >> n;
		int sx, sy;
		cin >> sx >> sy;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b }); //ÆíÀÇÁ¡
		}
		
		cin >> ex >> ey;

		flag = false;
		dfs(sx, sy); 

		if (flag) cout << "happy"<<"\n";
		else cout << "sad"<<"\n";
	}

	return 0;
}