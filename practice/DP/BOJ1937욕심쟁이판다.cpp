#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 510;
int n;
int arr[MAX][MAX];
int dp[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int solve(int x, int y) {

	int& ret = dp[x][y];
	if (ret != -1) return ret;

	dp[x][y] = 1; //그 자리에서 살수있는 일수는 1

	for (int i = 0; i < 4; i++) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];

		if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n || arr[x][y]>=arr[nextx][nexty]) continue;

		dp[x][y] = max(dp[x][y], solve(nextx,nexty) + 1);
	}

	return ret;
}


int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	memset(dp, -1, sizeof(dp));
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	int res = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			 res = max(res,solve(i, j));	
		}
	}
	cout << res << "\n";
	return 0;
}