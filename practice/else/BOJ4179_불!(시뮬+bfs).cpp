/*
	불이 여러곳에서 일어날수 있음에 주의.
	1. 불을 바로 큐에 넣어줘야되고
	2. fire배열을 INF로 초기화 하고 bfs돌면서 최솟값으로 갱신(다익스트라)
	3. 이동
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int r, c;
const int INF = 987654321;
const int MAX = 1010;
char arr[MAX][MAX];
int fire[MAX][MAX];
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int sx = 0; int sy = 0;
int fx = 0; int fy = 0;
queue <pair<int, int>> fireq;

int solve() {

	bool check[1010][1010] = { 0, };
	queue <pair<int, int>> q;
	q.push({ sx,sy });
	check[sx][sy] = true;
	int cnt = 0;

	while (!q.empty()) {

		int size = q.size();
		cnt++;
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == 0 || y == 0 || x == r - 1 || y == c - 1) return cnt;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= r || ny >= c || arr[nx][ny] == '#' || check[nx][ny]) continue;

				if (cnt < fire[nx][ny]) {
					check[nx][ny] = true;
					q.push({ nx,ny });
				}

			}
		}
	}
	return -1;
}

void firenumber() {

	while (!fireq.empty()) {

		int size = fireq.size();
		while (size--) {
			int x = fireq.front().first;
			int y = fireq.front().second;
			fireq.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= r || ny >= c || arr[nx][ny] == '#') continue;

				if (fire[nx][ny] > fire[x][y] + 1) {
					fire[nx][ny] = fire[x][y] + 1;
					fireq.push({ nx,ny });
				}
			}
		}
	}

}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			fire[i][j] = INF;
			if (arr[i][j] == 'J') {
				sx = i; sy = j;
			}
			else if (arr[i][j] == 'F') {
				fireq.push({ i,j });
				fire[i][j] = 0;
			}
		}
	}

	firenumber();

	int res = solve();
	if (res == -1) cout << "IMPOSSIBLE" << "\n";
	else cout << res << "\n";

	return 0;
}