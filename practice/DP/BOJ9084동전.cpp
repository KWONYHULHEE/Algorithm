#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10001;
int n, k;
int arr[110];
int dp[MAX];
int tc;

int main() {
	
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {

		fill(arr, arr + 110, 0);
		fill(dp, dp + MAX, 0);

		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);

		scanf("%d", &k);

		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = arr[i]; j <= k; j++) {
				dp[j] += dp[j - arr[i]]; 
			}
		}
		
		 printf("%d\n", dp[k]);
	}

	return 0;
}