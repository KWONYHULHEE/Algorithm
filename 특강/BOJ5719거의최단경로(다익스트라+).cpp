#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
const int MAX = 510;

int n, m;
int s, d;
vector<pair<int, int>> adj[MAX];
vector<pair<int, int>> rev[MAX];

int dist[MAX];
bool visited[MAX];
bool check[MAX][MAX];

// �� ������ �ٸ� �������� �ּҰŸ��� ���ϴ� �˰��� 

void dijkstra() {

	priority_queue<pair<int, int>> pq;
	fill(dist, dist + MAX, INF);
	fill(visited, visited + MAX, false);
	dist[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty()) {

		int cur = pq.top().second;
		pq.pop();

		//	visited[cur] = true;  ???

		for (int i = 0; i<adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int d = adj[cur][i].second;

			if (check[cur][next])continue;
			if (dist[cur] + d < dist[next]) {
				dist[next] = dist[cur] + d;
				pq.push({ dist[next],next });
			}
		}
	}
}

// �ִ� ��� �����ִ� ������ �Ѵ�.
void bfs() {

	queue<int> q;
	q.push(d);

	while (!q.empty()) {

		int cur = q.front();
		q.pop();
		// �������� ������ ����
		if (cur == s)continue;
		// ���� ������ �̾����� ����������

		for (int i = 0; i<rev[cur].size(); i++) {
			int prev = rev[cur][i].first;
			int d = rev[cur][i].second;
			// �ش� ��ΰ� �ִܰ���� ��� ǥ�����ְ� ť�� �־��ش�.
			if (dist[prev] + d == dist[cur]) {
				check[prev][cur] = true;
				q.push(prev);
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);

	while (1) {

		cin >> n >> m;
		if (n == 0 && m == 0)break;

		for (int i = 0; i < MAX; ++i) {
			adj[i].clear();
			rev[i].clear();
		}

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				check[i][j] = false;
			}
		}

		cin >> s >> d;
		int a, b, c;

		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> c;

			adj[a].push_back({ b, c });
			rev[b].push_back({ a, c });
		}

		dijkstra();
		bfs();
		dijkstra();

		cout << (dist[d] == INF ? -1 : dist[d]) << '\n';
	}
	return 0;
}