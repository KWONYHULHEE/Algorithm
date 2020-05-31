#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321;
const int MAX = 1010;
int n;
int arr[MAX];
int dp[MAX];


int dfs(int x) {
	if (x == n - 1) return 0;
	if (x >= n) return INF;

	int &ret = dp[x];
	if (ret != -1) return ret;

	ret = INF;

	for (int i = 1; i <= arr[x]; i++) {
		ret = min(ret, 1 + dfs(x + i));
	}

	return ret;

}
int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	int ans = dfs(0);

	
	if (ans == INF) cout << -1 << "\n";
	else cout << ans << "\n";

	return 0;

}

