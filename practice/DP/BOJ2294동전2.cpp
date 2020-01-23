#include <cstdio>
#include <algorithm>
using namespace std;

int n,k;
int arr[110];
int dp[10001];
const int INF = 10001;

int main() {


	scanf("%d %d", &n,&k);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= k; i++)
		dp[i] = INF;
	
	for (int i = 1; i <= n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - arr[i]]+1); // arr[i]������ ����� ����Ǽ� + 1(���ڽ� ���� 1���� �߰�)
		}
	}
	if (dp[k] == INF) printf("-1\n");
	else printf("%d\n", dp[k]);
	

	return 0;
}