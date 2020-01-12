#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

/*

P가 너무 크기 때문에 K를 이용하여 답을 구해내야 한다.
우선 K이하의 소수를 에라토스테네스의 체를 이용하여 구해준 뒤
P가 해당 소수들 중 하나라도 나누어 떨어지는 수가 있다면 BAD를 출력하게 된다.

*/

const int MAX = 1000003;

int K, num;
char P[110];
int ary[MAX - 1];

void primeNum() {
	int sqrt_N = sqrt(MAX) - 1;
	for (int i = 2; i<sqrt_N; i++) {
		if (ary[i] == 0) continue;
		for (int j = i + i; j<MAX; j += i) {
			ary[j] = 0;
		}
	}
}

bool solve(int k) {
	int temp = 0;
	for (int i = 0; P[i]; i++) {  //해당 요소 중 하나가 널 요소가 될 때까지 실행을 유지
		temp = (temp * 10 + (P[i] - '0')) % k;  //나머지값  
	}
	return temp ==0 ? true : false;
}

int main() {

	cin >> P >> K;

	for (int i = 2; i<MAX; i++) ary[i] = i;

	primeNum();

	bool flag = false;

	for (int i = 2; i<K; i++) {
		if (ary[i] == 0) continue;
		if (solve(i)) { //  나누어지면 BAD 안나누어지면 GOOD
			flag = true;
			num = i;
			break;
		}
	}

	if (!flag) cout << "GOOD";
	else cout << "BAD " << num;

	return 0;
}

