#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;

int mem[101], cost[101];
int dp[10101];

/*
dp[i] = i������� ������ִ� �ִ�޸�


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

			//c - cost[i] ���� cost[i]�� ū���̿��� ���� dp���� �����ϴ°�
			//���ο� ���Ҹ� ������ ������Ʈ �Ҷ��� �ڿ��� ���� ������Ʈ�ؾ� ��ġ�� ���� �� �ִ�!


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
