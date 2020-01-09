#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

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

