#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1010;
int arr[MAX];
int dp[2][MAX][MAX];

int solve(int turn, int left, int right) {
	
	if (left == right) {
		if (turn == 0) return arr[left];
		else return 0;
	}

	int& ret = dp[turn][left][right];
	if (ret != -1) return ret;

	if (turn == 0) {
		ret = arr[left] + solve(1, left + 1, right);
		ret = max(ret, arr[right] + solve(1, left, right - 1));
	}
	else {
			ret = solve(0, left + 1, right);
			ret = min(ret, solve(0, left, right - 1));	
	}
	return ret;
}


int main() {


	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		memset(dp, -1, sizeof(dp));
		memset(arr,0 , sizeof(arr));

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		cout << solve(0, 0, n - 1) << "\n";

	}

	return 0;
}