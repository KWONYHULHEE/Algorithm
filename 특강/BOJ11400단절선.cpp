#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 100000
using namespace std;
int n, m, discovered[MAX_N + 1], cut[MAX_N + 1], d, a, b;
vector<vector<int>> vt;
vector<pair<int, int>> res;

int dfs(int here, int par) {

	discovered[here] = ++d;
	int ret = discovered[here];
	int child = 0;

	for (int i = 0; i < vt[here].size();i++) {
		int there = vt[here][i];

		if (there == par) //같은정점
			continue;

		if (!discovered[there]) {
			int temp = dfs(there, here);
			if (temp > discovered[here])
				res.push_back({ min(here,there),max(here,there) }); //(A<B)
			ret = min(ret, temp);
		}
		else
			ret = min(ret, discovered[there]);
	}
	return ret;
}

int main() {

	scanf("%d%d", &n, &m);

	vt.resize(n + 1);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		if (!discovered[i])
			dfs(i, 0);

	sort(res.begin(), res.end());

	printf("%d\n", res.size());

	for (int i=0;i<res.size();i++)
		printf("%d %d\n", res[i].first, res[i].second);

	return 0;
}


