#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int m, p;
int before[1010];
int after[1010];
int dp[1010][310]; //남은돈,지금까지푼문제

/*
	문제 링크(koitp.org/problem/SDS_PRO_8_3/)

*/

int solve(int money, int problem) {

	if (problem == p) return 0;
	//다풀면 종료

	int& ret = dp[money][problem];
	if (ret != -1) return -1;

	ret = 987654321;

	int M = money;
	int cnt = 0;
	int aftermoney = 0;
	int P = problem+1;

	while (1) {
		if (M >= before[P] && P<=p) {
			M -= before[P];
			aftermoney += after[P];
			P++;
			cnt++;
		}
		else break;
	}

	ret=min(ret,solve(m - aftermoney, P - 1)+1);
		
	return ret;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m >> p;

	for (int i = 1; i <= p; i++) {
		cin >> before[i] >> after[i];
	}

	memset(dp, -1, sizeof(dp));
	cout<<solve(m, 0)+2;



	return 0;
}
