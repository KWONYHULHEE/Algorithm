#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[110][10];
const int MOD = 1000000000;
int main() {

	cin >> n;

	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)  dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)  dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])% MOD;
		}
	}
	long long int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
	}

	cout << sum%MOD << "\n";

	return 0;
}