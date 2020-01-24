#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int t, m; // price, kind
vector<pair<int, int>> v; // price, count
int i, j;
int cnt = 0;
int dp[10001][101];
/*
dp[n][k] = n원을 동전 k개까지 교환할 때까지의 경우의 수

dp[n][k] = dp[n][k] + dp[n - (v * c)][k - 1] // v = 사용되는 동전의 금액, c = 동전 개수(1 ~ n)

=> n원을 k개까지의 경우의 수 + n - v * c(사용되는 동전) 원을 이전 동전까지(k-1) 교환할 때까지의 경우의 수


*/
int main() {
	

	scanf("%d %d", &t, &m);

	for (int i = 1; i <=m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
	}

	//sort(v.begin(), v.end());

	for (int i = 1; i <= m; i++) { // kind
		dp[0][i - 1] = 1;

		for (int j = 0; j <= v[i - 1].second; j++) { // count
			for (int k = j * v[i - 1].first; k <= t; k++) { // price
				dp[k][i] += dp[k - j * v[i - 1].first][i - 1];
			}
		}
	}
	printf("%d", dp[t][m]);
}