#include <iostream>
using namespace std;

int arr[510][2];
int dp[510][510];


/*

dp[i][j]를 i번째부터 j번째 행렬까지의 곱의 최소 연산 횟수라고 정의하자.
Floyd Warshall Algorithm과 비슷하게 처리하면 된다.

먼저 인접한 행렬의 최소 연산 횟수는 직접 구하고, 나머지 경우에는 3중 for문을 이용해 구합니다.
3중 for문의 가장 바깥쪽에서 i와 j의 차를 의미하는 m을 2부터 n까지 돌리고, 두 번째 for문은 i값을 돌립니다.
j값은 m과 i를 이용해 구할 수 있습니다. 세 번째 for문에서는 경유점을 의미하는 k를 [i, j) 범위에서 돌립니다.

*/



int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n; cin >> n;


	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}


	for (int i = 1; i<n; i++) {  //1차이나는 행렬끼리 
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}



	for (int m = 2; m <= n; m++) { //구간의 차이 
		for (int i = 1; i <= n - m; i++) { //시작
			int j = i + m;
			for (int k = i; k<j; k++) {  //k인덱스에서 자름
				int res = dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1];
				if (dp[i][j] == 0 || dp[i][j] > res) dp[i][j] = res;
				//dp가 설정안되있으면 갱신 || 설정되있는데 res보다 크면 res로갱신


			}
		}
	}


	cout << dp[1][n];
}