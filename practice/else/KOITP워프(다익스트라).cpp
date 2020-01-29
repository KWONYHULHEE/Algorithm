#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100010;
const int INF = 987654321;
int m, n;
vector <pair<int, int>> adj[MAX];
int dist[MAX];
priority_queue <pair<int, int>> pq;

int main() {


	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	fill(dist, dist + MAX, INF);

	dist[1] = 0;

	pq.push({ 0,1 });

	while (!pq.empty()) {

		int cur = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		if (dist[cur] < cost ) continue;

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int nextcost = cost + adj[cur][i].second;

			if (dist[next] > nextcost) {
				dist[next] = nextcost;
				pq.push({ nextcost,next });
			}
		}
	}

	dist[n]==INF ? cout<< "-1" :cout<<dist[n];


	return 0;
}