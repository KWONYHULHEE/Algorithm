#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, p, q;
int k;
vector <int> v[110];
bool check[110];
int res = -1;

void find(int x,int dep) {

	check[x] = true;

	if (x == q) {
		res = dep;
		return;
	}

	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];

		if (!check[y]) {
			find(y, dep + 1);
		}
	}
}
int main() {

	cin >> n >> p >> q >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	find(p, 0);
	cout << res;
	
	return 0;
}