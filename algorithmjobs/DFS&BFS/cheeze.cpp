#include <stdio.h>
const int MAX = 110;
int cnt = 0;
int n, m;
int arr[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int melt() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				cnt++;

			}
			else
				arr[i][j] = 0;
		}
	}

	return cnt;
}

void dfs(int x, int y) {

	arr[x][y] = -1;

	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];

		if (a < 0 || b < 0 || a >= n || b >= m) continue;

		if (arr[a][b] == 1)
			arr[a][b] = 2;
		else if (arr[a][b] == 0)
			dfs(a, b);
	}


}


int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int k = 0;
	int time = 0;

	while (1) {

		if (melt() == 0) break;
		else {
			k = cnt;
			dfs(0, 0);
			cnt = 0;
			time++;
		}
	}
	printf("%d\n%d", time, k);

	return 0;
}