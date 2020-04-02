#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int tc;
int n;
int ex, ey = 0;
int dx[] = { -1,-2,-2,-1,1,2,1,2 };
int dy[] = { -2,-1,1,2,-2,-1,2,1 };
int cnt = 0;

void solve(int a, int b) {
	bool check[310][310] = { 0, };
	queue <pair<int, int>>q;
	check[a][b] = true;
	q.push({ a,b });

	while (!q.empty()) {

		int size = q.size();
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == ex && y == ey) return;

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || check[nx][ny])continue;

				check[nx][ny] = true;
				q.push({ nx,ny });

			}
		}
		cnt++;
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cnt = 0;
		cin >> n;
		int a, b;
		cin >> a >> b;
		cin >> ex >> ey;

		solve(a,b);
		cout << cnt << "\n";
	}
	
	return 0;
}