#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[1010][1010];
int dp[1010][1010];

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int result = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
			dp[i][j] = result + arr[i][j];
		}
	}

	cout << dp[n][m];

	return 0;
}