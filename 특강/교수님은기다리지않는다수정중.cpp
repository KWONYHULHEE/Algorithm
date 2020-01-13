#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;
int n, m;
int Q[MAX][3];
bool visit[MAX];
vector <pair<int, long long>> adj[MAX];
long long w[MAX];
int root[MAX];

void dfs(int node, long long int weight) {

	w[node] = weight;
	visit[node] = true;

	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i].first;
		if (!visit[next])
			dfs(next, weight + adj[node][i].second);
	}
}

int find(int node) {

	if (root[node] == node) return node;
	else return root[node] = find(root[node]);

}

void Union(int a, int b)
{
	root[find(b)] = find(a);
}


void init() {
	for (int i = 0; i <= n; i++)   //초기화
	{
		visit[i] = w[i] = 0;
		root[i] = i;
		adj[i].clear();
		
	}
	
}
int main() {


	while (1) {
		scanf("%d %d", &n, &m);

		if (n == 0 && m == 0)break;

		init();
		char k[5];
		int W;

		for (int i = 0; i < m; i++) {
			
			scanf("%s %d %d", k, &Q[i][1], &Q[i][2]);
			if (k[0] == '!') {
				scanf("%d", &W);
				Q[i][0] = 0;
				adj[Q[i][1]].push_back(make_pair(Q[i][2] ,W));
				adj[Q[i][2]].push_back(make_pair(Q[i][1], -W));
			}
			else if (k[0] == '?')
			{
				Q[i][0] = 1;
			}

			for (int i = 1; i <= n; i++) {
				if (!visit[i]) {
					dfs(i, 0);
				}
			}

			for (int i = 0; i < m; i++)
			{
				if (Q[i][0] == 0) Union(Q[i][1], Q[i][2]);
				else {
					if (find(Q[i][1]) != find(Q[i][2])) printf("UNKNOWN\n"); //같은그룹이 아니면
					else printf("%lld\n", w[Q[i][2]] - w[Q[i][1]]);
				}

			}


		}

	}

	return 0;
}