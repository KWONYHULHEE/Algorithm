#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
int arr[110][110];
long long dp[110][110];

long long solve(int x, int y) {

	if (x < 0 || y < 0 || x >= n || y >= n) return 0;
	if (x == n - 1 && y == n - 1) return 1;
	long long& ret = dp[x][y];
	if (ret != -1) return ret;

	ret = 0;
	ret += solve(x + arr[x][y], y);
	ret += solve(x, y + arr[x][y]);


	return ret;

}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));


	cout << solve(0, 0);





	return 0;
}