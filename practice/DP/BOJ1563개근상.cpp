#include <iostream>
#include <cstring>
using namespace std;

int n;
const int MAX = 1010;
int dp[MAX][MAX][3][2];

int solve(int days, int attend, int absent, int late) {

	if (absent == 3 || late == 2) return 0;
	if (days == n) return 1;
	
	int& ret = dp[days][attend][absent][late];
	if (ret != -1) return ret;

	ret = solve(days + 1, attend + 1, 0, late) + solve(days + 1, attend, absent + 1, late) + solve(days + 1, attend, 0, late + 1);


	return ret%=1000000;
	
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	memset(dp, -1, sizeof(dp));
	
	cout << solve(0,0,0,0)% 1000000;

	return 0;
}