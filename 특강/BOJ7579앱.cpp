#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;

int mem[101], cost[101];
int dp[101][10101];

/*
dp[i] = i비용으로 지울수있는 최대메모리

*/

int main() {

	int cost_sum = 0;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)

		scanf("%d", &mem[i]);

	for (int i = 1; i <= N; i++)

		scanf("%d", &cost[i]), cost_sum += cost[i];


	int ans = 987654321;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= cost_sum; j++) {
			if (j < cost[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + mem[i]);

			if (dp[i][j] >= M && j < ans) ans = j;
		}
	}


	printf("%d\n", ans);

	return 0;

}


/*

5 60
30 10 20 35 40
3 0 3 5 4

*/
