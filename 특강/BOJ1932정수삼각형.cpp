#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[510][510];
int dp[510][510];

int main() {



	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}





	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	int res = -1;

	for (int j = 1; j <= n; j++)
		res = max(res, dp[n][j]);


	cout << res << "\n";

	return 0;
}