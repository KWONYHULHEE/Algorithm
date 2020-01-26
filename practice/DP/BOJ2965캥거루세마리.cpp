#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 110;
int a, b, c;
int arr[MAX];

int dp[MAX][MAX][MAX];

int solve(int left, int mid,int right) {

	if (left + 1 == mid && mid + 1 == right) return 0;
	

	int& ret = dp[left][mid][right];
	if (ret != -1) return ret;

	for (int i = left + 1; i < mid; i++) {
		ret = max(ret, solve(left, i, mid)+1);
	}

	for (int i = mid + 1; i < right; i++) {
		ret = max(ret, solve(mid, i, right) + 1);
	}

	return ret;
	
}


int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b >> c;


	memset(dp, -1, sizeof(dp));
	
	cout << solve(a,b,c)<< "\n";


	return 0;
}