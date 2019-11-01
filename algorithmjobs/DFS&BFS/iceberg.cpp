#include <stdio.h>

int n, m;
const int MAX = 310;
int arr[MAX][MAX];
int copy[MAX][MAX];
int group = 0;
bool check[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int melt(int x, int y) {
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];

		if (a < 0 || b < 0 || a >= n || b >= m) continue;
		if (arr[a][b] == 0)
			cnt++;
	}

	return cnt;
}

void dfs(int x, int y) {
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];

		if (a < 0 || b < 0 || a >= n || b >= m)continue;

		if (copy[a][b] != 0 && check[a][b] == false)
			dfs(a, b);
	}
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			copy[i][j] = arr[i][j];
		}
	}
	int count = 0;


	while (1) {

		// bool check2[MAX][MAX]={0, };
		count++;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					// check2[i][j]=true;
					copy[i][j] -= melt(i, j);
					if (copy[i][j] < 0)
						copy[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (copy[i][j] != 0 && check[i][j] == false) {
					dfs(i, j);
					group++;
				}
			}
		}


		if (group == 0) {
			printf("0");
			return 0;
		}


		if (group >= 2) {
			printf("%d", count);
			return 0;
		}

		group = 0;                           //√ ±‚»≠
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = copy[i][j];
				check[i][j] = false;
			}
		}
	}

	return 0;
}