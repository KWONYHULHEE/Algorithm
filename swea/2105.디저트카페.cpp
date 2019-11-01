#include <cstdio>

int n; int sx = 0; int sy = 0;
int arr[30][30];
bool check[120];
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };
int res = -1;

void dfs(int x, int y, int cnt, int dir) {

	int a = x + dx[dir];
	int b = y + dy[dir];

	if (a >= 0 && b >= 0 && a < n&&b < n) {
		if (!check[arr[a][b]]) {
			check[arr[a][b]] = true;
			dfs(a, b, cnt + 1, dir);
			check[arr[a][b]] = false;
		}
		else if (a == sx && b == sy) {
			if (res < cnt)
				res = cnt;
			return;
		}
	}

	dir += 1;
	if (dir > 3) return;

	a = x + dx[dir];
	b = y + dy[dir];

	if (a >= 0 && b >= 0 && a < n&&b < n) {
		if (!check[arr[a][b]]) {
			check[arr[a][b]] = true;
			dfs(a, b, cnt + 1, dir);
			check[arr[a][b]] = false;
		}
		else if (a == sx && b == sy) {
			if (res < cnt)
				res = cnt;
			return;
		}
	}

}



int main() {

	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sx = i;
				sy = j;
				check[arr[i][j]] = true;
				dfs(i, j, 1, 0);
				check[arr[i][j]] = false;
			}
		}
		printf("#%d %d\n", t, res);
		res = -1;
	}
	return 0;
}