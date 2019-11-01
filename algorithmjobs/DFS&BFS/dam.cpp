#include <cstdio>
#include <queue>
using namespace std;
int cnt = 0;
int t;
const int MAX = 110;
int arr[MAX][MAX];
int x, y;
int k;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

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

			for (int i = 0; i < 4; i++) {
				Point next;
				next.x = current.x + dx[i];
				next.y = current.y + dy[i];

				if (next.x <= 0 || next.y <= 0 || next.x > t || next.y > t || arr[next.x][next.y] == -1) continue;

				if (check[next.x][next.y] == false) {
					check[next.x][next.y] = true;
					arr[next.x][next.y] = cnt;
					q.push(next);
				}
			}


		}
	}





}
int main() {

	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= t; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
				arr[i][j] = -1;
		}
	}

	scanf("%d %d", &x, &y);
	scanf("%d", &k);
	arr[y][x] = -1;
	bfs(y, x);
	int count = 0;
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= t; j++) {
			if (arr[i][j] == k)
				count++;
		}

	}
	if (count == 0) printf("-1");
	else printf("%d", count);
	return 0;

}