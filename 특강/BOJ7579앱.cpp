#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;

int mem[101], cost[101];
int dp[10101];

/*
dp[i] = i비용으로 지울수있는 최대메모리


*/

int main() {

	int cost_sum = 0;

	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++)

		scanf("%d", &mem[i]);

	for (int i = 1; i <= N; i++)

		scanf("%d", &cost[i]), cost_sum += cost[i];


	for (int i = 1; i <= N; i++) {
		
		for (int c = cost_sum; c >= cost[i]; c--) {

	
			dp[c] = max(dp[c], dp[c - cost[i]] + mem[i]);

			//c - cost[i] 에서 cost[i]가 큰값이여야 작은 dp부터 시작하는거
			//새로운 원소를 넣으며 업데이트 할때는 뒤에서 부터 업데이트해야 겹치지 않을 수 있다!


		}

	}

	int ans;

	for (int c = 0; c <= cost_sum; c++) {

		if (dp[c] >= M) {

			ans = c;

			break;

		}

	}

	printf("%d\n", ans);

	return 0;

}
