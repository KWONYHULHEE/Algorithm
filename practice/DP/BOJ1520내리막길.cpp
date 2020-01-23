#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
int arr[510][510];
int dp[510][510];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int solve(int x, int y) {

	if (x == 1 && y == 1) return 1; //기저
	if (dp[x][y]!=-1) return dp[x][y]; //이미 방문함

	dp[x][y] = 0; //방문체크

	for (int i = 0; i < 4; i++) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];

		if (nextx > 0 && nexty > 0 && nextx <= n && nexty <= m && arr[x][y] < arr[nextx][nexty]) {

			dp[x][y] += solve(nextx, nexty);
		}
	}

	return dp[x][y];

}



int main() {


	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= m; j++) {
		scanf("%d", &arr[i][j]);
		dp[i][j] = -1;
	}
}

	
	printf("%d\n", solve(n, m));

	return 0;
}