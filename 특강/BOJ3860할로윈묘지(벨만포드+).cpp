#include <iostream>
#include <cstring>
#define INF 987654321

using namespace std;

int dist[1000];
bool stone[35][35];
bool ghost[35][35];


/*
	 벨만포드
	 모든 정점의 개수는 w*h-g로 구할 수 있고, 간선의 개수는 간선을 추가할 때마다 1씩 늘려가며 구했다.
	 주의할 점은 간선을 구할 때 출구인 (x == h-1 && y == w-1)에서는 간선을 만들면 안된다.

*/

struct edge {
	int from, to, cost;
}E[5000];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {

	while (1) {
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		memset(stone, false, sizeof(stone));
		memset(ghost, false, sizeof(ghost));

		for (int i = 0; i < w*h; i++) {
			dist[i] = INF;
		}
		dist[0] = 0;

		int g;
		cin >> g;
		for (int i = 0; i < g; i++) {
			int x, y;
			cin >> y >> x;
			stone[x][y] = true;
		}


		//간선생성

		int edgeIdx = 0;

		int e;
		cin >> e;
		for (int i = 0; i < e; i++) {
			int fx, fy, tx, ty, t;
			cin >> fy >> fx >> ty >> tx >> t;
			E[edgeIdx].from = (fx * w + fy);
			E[edgeIdx].to = (tx * w + ty);
			E[edgeIdx++].cost = t;
			ghost[fx][fy] = true;
		}

		for (int x = 0; x < h; x++) {
			for (int y = 0; y < w; y++) {
				if (stone[x][y] || ghost[x][y] || (x == h - 1 && y == w - 1)) continue;	//묘비이거나 귀신구멍이면 다시
				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];
					if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
					if (stone[nx][ny]) continue;

					E[edgeIdx].from = (x * w + y);
					E[edgeIdx].to = (nx * w + ny);
					E[edgeIdx++].cost = 1; //시간1씩증가
				}
			}
		}


		//벨만포드

		int v = w * h - g;
		bool cycle = false;

		for (int i = 0; i < v; i++) { //모든 노드
			for (int j = 0; j < edgeIdx; j++) {  //엣지안에 from to 있으니까 2중for문으로
				if (dist[E[j].from] != INF && dist[E[j].to] > dist[E[j].from] + E[j].cost) {
					dist[E[j].to] = dist[E[j].from] + E[j].cost;
					if (i == v - 1) cycle = true;
				}
			}
		}
		 

		//마지막 노드에서의 가중치 출력

		if (cycle) cout << "Never\n";
		else if (dist[w*h - 1] == INF) cout << "Impossible\n";
		else cout << dist[w*h - 1] << "\n";
	}
}