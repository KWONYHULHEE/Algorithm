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

예를들어, 

    dp[1][8] = 1    (8 = 8)
    dp[2][5] = 1    (8 - 3 = 5)
    dp[2][11] = 1  (8 + 3 = 11)

dp[i-1][j] != 0일때
dp[i][j+ar[i]] += dp[i-1][j], 
dp[i][j-ar[i]] += dp[i-1][j]  이다!, 단 여기서 j-ar[i] > 20 이거나 j < 0 인 경우는 제외한다.
*/

int main() {

	int N;
	int ar[101] = { 0 };
	long dp[101][21] = { 0 };


	cin >> N;
	N--;
	for (int i = 0; i < N; i++)
		cin >> ar[i];

	int last;
	cin >> last;
    N++;
	
 dp[0][ar[0]] = 1;
    
        for(int i = 1; i < N-1; i++){
            for(int j = 0; j <= 20; j++){
                if(dp[i-1][j] != 0){
                    if(j-ar[i] >= 0){
                        dp[i][j-ar[i]] += dp[i-1][j];                       
                    }
                    if(j+ar[i] <= 20){                       
                        dp[i][j+ar[i]] += dp[i-1][j];
                    }
                }
            }
        }


	cout << dp[N -2][last] << endl;
	return 0;
}
