#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

using namespace std;


const int INF = 987654321;

vector<pair<int, int> > adj[1002];
priority_queue<int> dist[1002];

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < m; i++)
	{
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);

		adj[from].push_back({ val, to });
	}

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

	pq.push({ 0, 1 });
	dist[1].push(0);

	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		for (int i = 0; i < adj[here].size(); i++)
		{
			int next = adj[here][i].second;
			int nextCost = adj[here][i].first;

			if (dist[next].size() < k)
			{
				dist[next].push(nextCost + cost);
				pq.push({ nextCost + cost, next });
			}
			else if (dist[next].top() > nextCost + cost)
				//2. k개의 경로가 이미 존재할 경우 heap의 root 노드가 k번째 최단경로가 된다.
				//이 경로보다 작은 경우 기존의 k번째 경로를 제거하고 넣어준다.
			{
				dist[next].pop();
				dist[next].push(nextCost + cost);
				pq.push({ nextCost + cost, next });
			}

		}
	}

	for (int i = 1; i <= n; i++)
		dist[i].size() == k ? printf("%d\n", dist[i].top()) : printf("-1\n");



	return 0;
}
