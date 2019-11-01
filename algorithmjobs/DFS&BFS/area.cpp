#include <stdio.h>
#include <algorithm>
using namespace std;

int m, n, k;
const int MAX = 110;
int arr[MAX][MAX];
int total[MAX];
int cnt = 0;
int group = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
bool check[MAX][MAX];

void dfs(int x, int y) {
	check[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];

		if (a < 0 || b < 0 || a >= m || b >= n) continue;

		if (check[a][b] == false && arr[a][b] == 0) {
			dfs(a, b);
		}
	}

}


int main() {
	scanf("%d %d %d", &m, &n, &k);


	for (int p = 0; p < k; p++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				arr[j][i] = 1;
			}
		}

	}

	int t = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 && check[i][j] == false) {
				dfs(i, j);
				group++;
				total[t++] = cnt;
				cnt = 0;
			}
		}
	}

	printf("%d\n", group);
	sort(total, total + t);
	for (int i = 0; i < t; i++)
		printf("%d ", total[i]);


	return 0;

}