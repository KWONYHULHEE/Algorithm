#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 4010;
int dp[MAX][MAX];  
//n의 i번째 문자와 m의 j번째 문자를 끝으로 하는 부분 문자의 최대
// 공통부분 문자열의 길이

int main() {

	string n, m;

	cin >> n >> m;
	int res = 0;  //****

	for (int i = 1; i <=n.size(); i++) {
		for (int j = 1; j <= m.size(); j++) {
			if (n[i-1] == m[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				res = max(res, dp[i][j]);
			}
		}
	}


	cout << res << "\n";
	return 0;

}
