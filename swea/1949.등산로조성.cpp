#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int arr[20][20];
int str[20][20];
int k;
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

struct Point {
	int x, y;
};

void cutting(int x, int y, int cut) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			str[i][j] = arr[i][j];
		}
	}
	str[x][y] -= cut;
	if (str[x][y] < 0) str[x][y] = 0;
}

int bfs(int x, int y) {
	queue <Point> q;
	Point p;
	p.x = x;
	p.y = y;
	q.push(p);
	int cnt = 0;

	while (!q.empty()) {
		int size = q.size();
		cnt++;
		while (size--) {
			Point cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				Point next;
				next.x = cur.x + dx[i];
				next.y = cur.y + dy[i];

				if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= n) continue;

				if (str[next.x][next.y] < str[cur.x][cur.y]) {
					q.push(next);
				}
			}
		}
	}
	return cnt;
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		int tot = 0;
		int maxheight = -1;
		vector <Point> start;

		scanf("%d %d", &n, &k);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				if (maxheight < arr[i][j])
					maxheight = arr[i][j];
			}
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == maxheight)
					start.push_back({ i,j });
			}
		}

		for (int i = 0; i < start.size(); i++) {
			int p = start[i].x;
			int q = start[i].y;
			for (int j = 0; j <= k; j++) {
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < n; b++) {
						cutting(a, b, j);
						int res = bfs(p, q);
						if (res > tot) tot = res;
					}
				}
			}
		}

		printf("#%d %d\n", t, tot);

	}
	return 0;
}