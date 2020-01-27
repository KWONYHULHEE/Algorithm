#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;
int arr[110];
int dp[110][35];

int solve(int date,int coup) {

	if (date > n) return 0;

	int& ret = dp[date][coup];
	if (ret != -1) return ret;

	ret = 987654321;

	if (arr[date] == 0) {
		if (coup >= 3) ret = min(ret, solve(date + 1, coup - 3));
		ret = min(ret, solve(date + 5, coup + 2) + 37000); //5일권
		ret = min(ret, solve(date + 3, coup + 1) + 25000); //3일권
		ret = min(ret, solve(date + 1, coup) + 10000);  //하루권
	}
	else
		ret = min(ret, solve(date + 1, coup));
	
	return ret;

}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >>m;
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <=m; i++)
	{
		int a;
		cin >> a;
		arr[a] = 1;
	}
	cout<<solve(1,0);

	return 0;
}