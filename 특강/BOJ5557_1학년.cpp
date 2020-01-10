#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
/*

DP 문제로 항상 0보다 크거나 같고 20보다 작거나 같은 것이 이 문제의 핵심이다.

점화식을 세울 때, N번째의 경우의 수는

1)N-1번째에 구한 경우의 수에서 다음 숫자를 더했을 때 20보다 작거나 같고
 
2)다음 숫자를 뺏을 때 0보다 크거나 같을 때

N-1번째의 경우의 수를 더해주면 N번째의 경우의 수가 나온다.

dp[i][j] : 'i번째 수 까지 계산을 했을 때 j를 만들 수 있는 경우의 수'

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
	dp[0][arr[0]]=1;  //1번째 수 까지 계산했을때 arr[1]을 만들수 있는 경우의 수는 1이다.
	
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
