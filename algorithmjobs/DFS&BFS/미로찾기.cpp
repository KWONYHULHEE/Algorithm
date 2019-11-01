#include <stdio.h>
#include <queue>
using namespace std;
int n, m;
const int MAX = 1010;
int arr[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int cnt = 0;

struct Point {
	int x;
	int y;
};
void bfs(int x, int y) {
	bool check[MAX][MAX] = { 0, };
	queue <Point> q;
	Point p;
	p.x = x;
	p.y = y;
	q.push(p);
	check[x][y] = true;

	while (!q.empty()) {
		int size = q.size();
		cnt++;
		while (size--) {
			Point current = q.front();
			q.pop();

			if (current.x == 0 && current.y == m - 1)
				return;

			for (int i = 0; i < 4; i++) {
				Point next;
				next.x = current.x + dx[i];
				next.y = current.y + dy[i];

				if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;

				if (check[next.x][next.y] == false && arr[next.x][next.y] == 0) {
					check[next.x][next.y] = true;
					q.push(next);
				}
			}


		}
	}
}



int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	bfs(n - 1, 0);
	printf("%d", cnt - 1);

	return 0;
}