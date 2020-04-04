#include <string>
#include <vector>
#include <queue>
using namespace std;
vector <int> graph[200010];
int dist[200010];

void bfs(int x) {
	bool check[200010] = { 0, };
	check[x] = true;
	queue <int> q;
	q.push(x);
	dist[x] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!check[next]) {
				check[next] = true;
				dist[next] = dist[cur] + 1;
			}
		}
	}
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	for (int i = 0; i < edge.size(); i++) {
		int a = edge[i][0];
		int b = edge[i][1];
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(1);

	for (int i = 1; i <=n; i++) {
		if (dist[i] > answer) answer = dist[i];
	}
	return answer;
}