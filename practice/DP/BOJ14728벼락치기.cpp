#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, t;
int dp[110][10010];
int arr[1010][1010];

int solve(int chap, int time) {

	if (chap == n) return 0;

	int& ret = dp[chap][time];
	if (ret != -1) return ret;

	if (arr[chap][0] <= time)
		ret = arr[chap][1] + solve(chap + 1, time - arr[chap][0]);
	ret = max(ret, solve(chap + 1, time));

	return ret;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> t;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i][0] = a;
		arr[i][1] = b;
	}
	cout << solve(0, t);


	return 0;
}