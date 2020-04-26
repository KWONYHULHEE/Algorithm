#include <string>
#include <vector>
#include <string.h>

using namespace std;
int result = 0;
int dp[110][100010];
void go(int sum, int index, vector<int> coin, int total, int len) {

	if (sum == total) {
		result++;
		result %= 1000000007;
		return;
	}
	int& ret = dp[index][sum];
	if (ret != -1) return ret;


	for (int i = index; i < len; i++) {
		if (sum + coin[i] <= total) {
			go(sum + coin[i], i, coin, total, len);
		}
		else return;
	}
}
int solution(int n, vector<int> money) {
	int answer = 0;
	memset(dp, -1, sizeof(dp));
	go(0, 0, money, n, money.size());
	answer = result;
	return answer;
}