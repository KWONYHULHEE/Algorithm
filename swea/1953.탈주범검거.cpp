#include <cstdio>
#include <queue>
using namespace std;


int n, m, r, c, l;
int arr[60][60];
int str[60][60];
int dx_1[] = { -1,1,0,0 };
int dy_1[] = { 0,0,1,-1 };
int dx_2[] = { -1,1 };
int dy_2[] = { 0,0 };
int dx_3[] = { 0,0 };
int dy_3[] = { -1,1 };
int dx_4[] = { -1,0 };
int dy_4[] = { 0,1 };
int dx_5[] = { 1,0 };
int dy_5[] = { 0,1 };
int dx_6[] = { 1,0 };
int dy_6[] = { 0,-1 };
int dx_7[] = { -1,0 };
int dy_7[] = { 0,-1 };

struct Point {
	int x;
	int y;
};

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			str[i][j] = 0;
		}
	}
}
void bfs(int x, int y) {
	queue <Point> q;
	int cnt = 1;
	bool check[60][60] = { 0, };
	check[x][y] = true;
	Point p;
	p.x = x;
	p.y = y;
	q.push(p);
	str[x][y] = 1;
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		while (size--) {
			Point cur = q.front();
			q.pop();

			if (arr[cur.x][cur.y] == 1) {

				for (int i = 0; i < 4; i++) {
					Point next;
					next.x = cur.x + dx_1[i];
					next.y = cur.y + dy_1[i];

					if (i == 0) {
						if (arr[next.x][next.y] == 3 || arr[next.x][next.y] == 4 || arr[next.x][next.y] == 7) continue;
					}
					else if (i == 1) {
						if (arr[next.x][next.y] == 3 || arr[next.x][next.y] == 5 || arr[next.x][next.y] == 6) continue;
					}
					else if (i == 2) {
						if (arr[next.x][next.y] == 2 || arr[next.x][next.y] == 4 || arr[next.x][next.y] == 5) continue;
					}
					else if (i == 3) {
						if (arr[next.x][next.y] == 2 || arr[next.x][next.y] == 6 || arr[next.x][next.y] == 7) continue;
					}



					if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;

					if (!check[next.x][next.y] && str[next.x][next.y] == 0 && arr[next.x][next.y] != 0) {
						check[next.x][next.y] = true;
						str[next.x][next.y] = cnt;
						q.push(next);
					}
				}

			}
			else if (arr[cur.x][cur.y] == 2) {

				for (int i = 0; i < 2; i++) {
					Point next;
					next.x = cur.x + dx_2[i];
					next.y = cur.y + dy_2[i];

					if (i == 0) {
						if (arr[next.x][next.y] == 3 || arr[next.x][next.y] == 4 || arr[next.x][next.y] == 7) continue;
					}
					else if (i == 1) {
						if (arr[next.x][next.y] == 3 || arr[next.x][next.y] == 6 || arr[next.x][next.y] == 5) continue;
					}

					if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;

					if (!check[next.x][next.y] && str[next.x][next.y] == 0 && arr[next.x][next.y] != 0) {
						str[next.x][next.y] = cnt;
						check[next.x][next.y] = true;
						q.push(next);
					}
				}

			}
			else if (arr[cur.x][cur.y] == 3) {

				for (int i = 0; i < 2; i++) {
					Point next;
					next.x = cur.x + dx_3[i];
					next.y = cur.y + dy_3[i];

					if (i == 0) {
						if (arr[next.x][next.y] == 2 || arr[next.x][next.y] == 6 || arr[next.x][next.y] == 7) continue;
					}
					else if (i == 1) {
						if (arr[next.x][next.y] == 2 || arr[next.x][next.y] == 4 || arr[next.x][next.y] == 5) continue;
					}

					if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;

					if (!check[next.x][next.y] && str[next.x][next.y] == 0 && arr[next.x][next.y] != 0) {
						str[next.x][next.y] = cnt;
						check[next.x][next.y] = true;
						q.push(next);
					}
				}

			}
			else if (arr[cur.x][cur.y] == 4) {

				for (int i = 0; i < 2; i++) {
					Point next;
					next.x = cur.x + dx_4[i];
					next.y = cur.y + dy_4[i];

					if (i == 0) {
						if (arr[next.x][next.y] == 3 || arr[next.x][next.y] == 4 || arr[next.x][next.y] == 7) continue;
					}
					else if (i == 1) {
						if (arr[next.x][next.y] == 2 || arr[next.x][next.y] == 4 || arr[next.x][next.y] == 5) continue;
					}

					if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;

					if (!check[next.x][next.y] && str[next.x][next.y] == 0 && arr[next.x][next.y] != 0) {
						str[next.x][next.y] = cnt;
						check[next.x][next.y] = true;
						q.push(next);
					}
				}

			}
			else if (arr[cur.x][cur.y] == 5) {

				for (int i = 0; i < 2; i++) {
					Point next;
					next.x = cur.x + dx_5[i];
					next.y = cur.y + dy_5[i];

					if (i == 0) {
						if (arr[next.x][next.y] == 3 || arr[next.x][next.y] == 5 || arr[next.x][next.y] == 6) continue;
					}
					else if (i == 1) {
						if (arr[next.x][next.y] == 2 || arr[next.x][next.y] == 4 || arr[next.x][next.y] == 5) continue;
					}

					if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;

					if (!check[next.x][next.y] && str[next.x][next.y] == 0 && arr[next.x][next.y] != 0) {
						str[next.x][next.y] = cnt;
						check[next.x][next.y] = true;
						q.push(next);
					}
				}

			}
			else if (arr[cur.x][cur.y] == 6) {

				for (int i = 0; i < 2; i++) {
					Point next;
					next.x = cur.x + dx_6[i];
					next.y = cur.y + dy_6[i];

					if (i == 0) {
						if (arr[next.x][next.y] == 3 || arr[next.x][next.y] == 5 || arr[next.x][next.y] == 6) continue;
					}
					else if (i == 1) {
						if (arr[next.x][next.y] == 2 || arr[next.x][next.y] == 6 || arr[next.x][next.y] == 7) continue;
					}

					if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;

					if (!check[next.x][next.y] && str[next.x][next.y] == 0 && arr[next.x][next.y] != 0) {
						str[next.x][next.y] = cnt;
						q.push(next);
					}
				}

			}
			else if (arr[cur.x][cur.y] == 7) {

				for (int i = 0; i < 2; i++) {
					Point next;
					next.x = cur.x + dx_7[i];
					next.y = cur.y + dy_7[i];

					if (i == 0) {
						if (arr[next.x][next.y] == 3 || arr[next.x][next.y] == 4 || arr[next.x][next.y] == 7) continue;
					}
					else if (i == 1) {
						if (arr[next.x][next.y] == 2 || arr[next.x][next.y] == 7 || arr[next.x][next.y] == 6) continue;
					}

					if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;

					if (!check[next.x][next.y] && str[next.x][next.y] == 0 && arr[next.x][next.y] != 0) {
						str[next.x][next.y] = cnt;
						check[next.x][next.y] = true;
						q.push(next);
					}
				}
			}
		}
	}
}

int main() {
	int testcase;
	int total = 0;
	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++) {
		scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		bfs(r, c);
		// for(int i=0;i<n;i++){
		//   for(int j=0;j<m;j++){
		//   printf("%d ",str[i][j]);
		//   }
		//   printf("\n");
		// }
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (str[i][j] <= l && str[i][j] != 0)
					total++;
			}
		}
		printf("#%d %d\n", t, total);
		total = 0;
		init();

	}
	return 0;
}