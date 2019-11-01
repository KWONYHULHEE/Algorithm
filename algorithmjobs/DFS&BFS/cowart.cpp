#include <stdio.h>

int n;
const int MAX = 110;
char arr[MAX][MAX];
char str[MAX][MAX];
int red = 0; int green = 0; int blue = 0;
bool check[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y, char color, char who[MAX][MAX]) {
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];

		if (a < 0 || b < 0 || a >= n || b >= n) continue;
		if (check[a][b] == false && who[a][b] == color)
			dfs(a, b, color, who);
	}
}
int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'R')
				str[i][j] = 'G';
			else
				str[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				if (arr[i][j] == 'R') {
					dfs(i, j, arr[i][j], arr);
					red++;
				}
				if (arr[i][j] == 'G') {
					dfs(i, j, arr[i][j], arr);
					green++;
				}
				if (arr[i][j] == 'B') {
					dfs(i, j, arr[i][j], arr);
					blue++;
				}
			}
		}
	}
	int person = red + green + blue;

	green = 0;
	blue = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				if (str[i][j] == 'G') {
					dfs(i, j, str[i][j], str);
					green++;
				}
				if (str[i][j] == 'B') {
					dfs(i, j, str[i][j], str);
					blue++;
				}
			}
		}
	}
	int cow = green + blue;

	printf("%d %d", person, cow);

	return 0;
}