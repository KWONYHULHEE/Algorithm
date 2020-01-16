#include <iostream>
using namespace std;

int arr[510][2];
int dp[510][510];


/*

dp[i][j]�� i��°���� j��° ��ı����� ���� �ּ� ���� Ƚ����� ��������.
Floyd Warshall Algorithm�� ����ϰ� ó���ϸ� �ȴ�.

���� ������ ����� �ּ� ���� Ƚ���� ���� ���ϰ�, ������ ��쿡�� 3�� for���� �̿��� ���մϴ�.
3�� for���� ���� �ٱ��ʿ��� i�� j�� ���� �ǹ��ϴ� m�� 2���� n���� ������, �� ��° for���� i���� �����ϴ�.
j���� m�� i�� �̿��� ���� �� �ֽ��ϴ�. �� ��° for�������� �������� �ǹ��ϴ� k�� [i, j) �������� �����ϴ�.

*/



int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n; cin >> n;


	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}


	for (int i = 1; i<n; i++) {  //1���̳��� ��ĳ��� 
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}



	for (int m = 2; m <= n; m++) { //������ ���� 
		for (int i = 1; i <= n - m; i++) { //����
			int j = i + m;
			for (int k = i; k<j; k++) {  //k�ε������� �ڸ�
				int res = dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1];
				if (dp[i][j] == 0 || dp[i][j] > res) dp[i][j] = res;
				//dp�� �����ȵ������� ���� || �������ִµ� res���� ũ�� res�ΰ���


			}
		}
	}


	cout << dp[1][n];
}