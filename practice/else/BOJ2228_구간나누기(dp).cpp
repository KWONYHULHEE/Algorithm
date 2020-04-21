/*
DP[n][m] = n���� ���ҵ��� ���տ��� m���� �������� �������� �� ���� �ִ밪

1. i�� ° ���� �������� �ʴ� ���

�̴� i - 1������ ���ҵ��� ���տ��� ���� m���� ���� ���� �ִ밪�� ����.
-> dp[i][m] =dp[i - 1][m]


2. i�� ° ���� �����ϴ� ���

i�� ° ���� �����ϴ� ������ m��° ������ �Ǿ�� �ϸ�
������ m - 1������ ������� ���� �ִ밪�� ���Ͽ��� �Ѵ�.
�� ��, i��° ���� �����ϴ� ������ ���������� ��������� �𸥴�.
���� �ݺ����� ���� ��� ��츦 ã�ƺ��� �� �� �ִ밪�� ã�� ���Ͽ� �ش�.


��, Max(dp[k - 2][m - 1] + Sum(data[k ~ i])

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

	ret = f(k - 1, cnt);  //k��°�� �Ȼ���
	for (int i = 1; i <= k; i++)  //k��°�� ����
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