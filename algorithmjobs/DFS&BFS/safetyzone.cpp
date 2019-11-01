#include <stdio.h>
int n;
int arr[110][110];
bool check[110][110];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}
}
void dfs(int x, int y, int t) {
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];
		if (a < 0 || b < 0 || a >= n || b >= n) continue;

		if (arr[a][b] > t && !check[a][b]) {
			dfs(a, b, t);
		}
	}


}
int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);
	int maxnum = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (maxnum < arr[i][j]) maxnum = arr[i][j];
		}
	}
	int count = 0;
	int res = 0;

	for (int t = 1; t <= maxnum; t++) {
		count = 0;
		init();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > t && !check[i][j]) {
					dfs(i, j, t);
					count++;
				}
			}
		}
		if (res < count) res = count;
	}

	printf("%d", res);
	return 0;
}