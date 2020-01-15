#include <cstdio>
#include <vector>
#include <queue>
#include <limits.h>
#include <functional>
using namespace std;
 
const int MAX = 20001;
const int INF = 987654321;
vector< pair<int, int>> adj[20001]; 
int dist[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;

int main()
{    
 
    int V, E, start;
    
    scanf("%d %d", &V, &E);    
    scanf("%d", &start);    
    
 
    for (int i = 0; i < E; i++)
    {
        int from, to, val;
        scanf("%d %d %d", &from, &to, &val);
 
        adj[from].push_back(make_pair(to, val));
    }


	fill(dist, dist + MAX, INF);

	dist[start] = 0;
	pq.push(make_pair(0, start));
	

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int here = pq.top().second;

		pq.pop();

		// 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸것을 무시한다.
		if (dist[here] < cost)
			continue;

		// 인접한 정점들을 모두 검사.
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			// 더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(make_pair(nextDist, there));

			}
		}
	}

 
    for (int i = 1; i <=V; i++)
        dist[i] == INF ? printf("INF\n") : printf("%d\n", dist[i]);
    
    return 0;
}

