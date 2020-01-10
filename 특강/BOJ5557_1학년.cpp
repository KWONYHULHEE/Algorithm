#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
/*

DP ������ �׻� 0���� ũ�ų� ���� 20���� �۰ų� ���� ���� �� ������ �ٽ��̴�.

��ȭ���� ���� ��, N��°�� ����� ����

1)N-1��°�� ���� ����� ������ ���� ���ڸ� ������ �� 20���� �۰ų� ����
 
2)���� ���ڸ� ���� �� 0���� ũ�ų� ���� ��

N-1��°�� ����� ���� �����ָ� N��°�� ����� ���� ���´�.

dp[i][j] : 'i��° �� ���� ����� ���� �� j�� ���� �� �ִ� ����� ��'

*/

int main() {

	int N;
	int arr[101] = { 0 };
	long dp[101][21] = { 0 };


	cin >> N;
	N--;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int last;
	cin >> last;
	dp[0][arr[0]]=1;  //1��° �� ���� ��������� arr[1]�� ����� �ִ� ����� ���� 1�̴�.
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j - arr[i] >= 0) {
				dp[i][j] += dp[i - 1][j - arr[i]];
			}
			if (j + arr[i] <= 20) {
				dp[i][j] += dp[i - 1][j + arr[i]];
			}
		}
	}

	cout << dp[N - 1][last] << endl;
	return 0;
}
