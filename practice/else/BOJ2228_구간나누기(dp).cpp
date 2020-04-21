/*
DP[n][m] = n개의 원소들의 집합에서 m개의 구간으로 나누었을 때 합의 최대값

1. i번 째 수를 포함하지 않는 경우

이는 i - 1까지의 원소들의 집합에서 구간 m개를 나눈 합의 최대값과 같다.
-> dp[i][m] =dp[i - 1][m]


2. i번 째 수를 포함하는 경우

i번 째 수를 포함하는 구간이 m번째 구간이 되어야 하며
이전에 m - 1구간을 만들었을 때의 최대값과 합하여야 한다.
이 때, i번째 수를 포함하는 구간의 시작지점이 어디인지를 모른다.
따라서 반복문을 통해 모든 경우를 찾아보고 그 중 최대값을 찾아 합하여 준다.


즉, Max(dp[k - 2][m - 1] + Sum(data[k ~ i])

*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int IMP = -1e9;

int n, m, dp[101][51], a[102], psum[102];
bool c[101][51];

int f(int k, int cnt) {

	if (cnt == 0) return 0;
	if (k <= 0) return IMP;

	int& ret = dp[k][cnt];
	if (c[k][cnt]) return ret;

	c[k][cnt] = true;

	ret = f(k - 1, cnt);  //k번째수 안뽑음
	for (int i = 1; i <= k; i++)  //k번째수 뽑음
		ret = max(f(i - 2, cnt - 1) + psum[k] - psum[i - 1], ret);

	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}

	memset(c, false, sizeof(c));

	cout << f(n, m) << '\n';
}