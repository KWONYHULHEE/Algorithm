#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 4010;
int dp[MAX][MAX];  
//n�� i��° ���ڿ� m�� j��° ���ڸ� ������ �ϴ� �κ� ������ �ִ�
// ����κ� ���ڿ��� ����

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
