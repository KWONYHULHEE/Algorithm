#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int leftvalue[2010];
int rightvalue[2010];
int dp[2010][2010];

int solve(int left, int right) {
	if (left > n || right > n) return 0;

	int& ret = dp[left][right];
	if (ret != -1) return ret;

	ret = solve(left + 1, right);
	ret = max(ret,solve(left + 1, right + 1));
	if (leftvalue[left] > rightvalue[right]) {
		ret = max(ret,solve(left, right + 1) + rightvalue[right]);
	}


	return ret;

}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <=n; i++) {
		cin >> leftvalue[i];
	}
	for (int i = 1; i <=n; i++) {
		cin >> rightvalue[i];
	}

	cout<<solve(1, 1);

	return 0;
}