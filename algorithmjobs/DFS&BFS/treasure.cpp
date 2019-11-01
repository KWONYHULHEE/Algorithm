#include <cstdio>
#include <queue>
using namespace std;

int n, m;
const int MAX = 60;
char arr[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };


struct Point {
	int x;
	int y;

};
int bfs(int x, int y) {
	bool check[MAX][MAX] = { 0, };
	queue <Point> q;
	int cnt = 0;
	check[x][y] = true;
	Point p;
	p.x = x;
	p.y = y;
	q.push(p);

	while (!q.empty()) {
		int size = q.size();
		cnt++;
		while (size--) {
			Point current = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				Point next;
				next.x = current.x + dx[i];
				next.y = current.y + dy[i];

				if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;

				if (arr[next.x][next.y] == 'L'&&check[next.x][next.y] == false) {
					check[next.x][next.y] = true;
					q.push(next);
				}
			}
		}
	}
	return cnt;
}

int main() {
	scanf("%d %d", &n, &m);
	int max = -1;
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				int res = bfs(i, j);
				if (max < res - 1) {
					max = res - 1;
				}
			}
		}
	}



	printf("%d", max);

	return 0;
}