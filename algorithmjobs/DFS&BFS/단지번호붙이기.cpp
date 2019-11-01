#include <stdio.h>
#include <queue>
#include <algorithm>
using  namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
bool check[40][40];
int arr[40][40];
int str[40][40];
int cnt = 1;
struct Point {
	int x;
	int y;
};
void bfs(int x, int y) {

	check[x][y] = true;
	queue <Point> q;
	Point p;
	p.x = x;
	p.y = y;
	q.push(p);

	while (!q.empty()) {

		Point current = q.front();
		q.pop();
		str[current.x][current.y] = cnt;

		for (int i = 0; i < 4; i++) {
			Point next;
			next.x = current.x + dx[i];
			next.y = current.y + dy[i];

			if (arr[next.x][next.y] == 1 && !check[next.x][next.y]) {
				check[next.x][next.y] = true;
				q.push(next);
			}
		}
	}
}
int main() {

	//Please Enter Your Code Here
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && !check[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	int value = cnt;
	int res[40] = { 0, };
	cnt--;

	while (cnt > 0) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (str[i][j] == cnt) {
					res[cnt]++;
				}
			}
		}
		cnt--;
	}

	sort(res, res + value);
	printf("%d\n", value - 1);
	for (int i = 1; i < value; i++) {
		printf("%d\n", res[i]);
	}
	return 0;
}