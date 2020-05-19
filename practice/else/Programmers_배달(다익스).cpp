#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 10000000;

vector<pair<int, int>> map[51];
int result[51];

void dijkstra(int start) {
	result[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int n = pq.top().first;
		int d = pq.top().second;
		pq.pop();

		if (result[n] < d) continue;

		for (int i = 0; i < map[n].size(); i++) {
			int n2 = map[n][i].first;
			int d2 = d + map[n][i].second;

			if (d2 < result[n2]) {
				result[n2] = d2;
				pq.push(make_pair(n2, d2));
			}
		}
	}
}

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;

	for (int i = 1; i <= N; i++) {
		result[i] = INF;
	}

	for (int i = 0; i < road.size(); i++) {
		int a = road[i][0];
		int b = road[i][1];
		int c = road[i][2];

		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));

	}

	dijkstra(1);

	for (int i = 1; i <= N; i++) {
		if (result[i] <= K) {
			answer++;
		}
	}

	return answer;
}