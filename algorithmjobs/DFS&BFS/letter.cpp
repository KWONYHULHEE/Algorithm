#include <stdio.h>
char arr[100][100];
int r, c;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool check[100];
int res = 0;

void dfs(int x, int y, int cnt) {
	check[arr[x][y] - '0'] = true;
	if (res < cnt)
		res = cnt;

	for (int i = 0; i < 4; i++) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];

		if (nextx < 0 || nexty < 0 || nextx >= r || nexty >= c) continue;

		if (check[arr[nextx][nexty] - '0'] == false) {
			check[arr[nextx][nexty] - '0'] = true;
			dfs(nextx, nexty, cnt + 1);
			check[arr[nextx][nexty] - '0'] = false;
		}
	}
	check[arr[x][y] - '0'] = false;
}

int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &r, &c);


	for (int i = 0; i < r; i++)
		scanf("%s", arr[i]);



	dfs(0, 0, 0);

	printf("%d", res + 1);
	return 0;
}