#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
왼쪽부터 gcd 값 기록하는 배열 하나

오른쪽부터 gcd 값 기록하는 배열 하나

만약 arr[0]인 8을 뺀다면 rtol[1]이 최대공약수가 된다.

만약 arr[1]인 12를 뺀다면 gcd(ltor[0],rtol[2])가 최대공약수가 된다.

즉, 해당 위치의 직전 최대공약수와 이후 최대공약수의 최대공약수가 전체의 최대공약수가 된다.



*/

const int MAX = 1000001;
int n, arr[MAX], ltor[MAX], rtol[MAX];

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	ltor[0] = arr[0];

	for (int i = 1; i < n; i++) {
		ltor[i] =gcd(ltor[i-1] ,arr[i]);
	}

	rtol[n-1] = arr[n-1];

	for (int i = n-2; i >=0; i--) {
		rtol[i] = gcd(rtol[i+1], arr[i]);
	}

	int max = -1;
	int num = -1;
	bool flag = false;

	for (int i = 0; i < n; i++) {
		int k,g;
		k = arr[i];
		g = gcd(ltor[i - 1], rtol[i + 1]);


		if (k >= g) {
			if (k%g == 0) continue;
			else {
				num = k;
				max = max < g ? g : max;
				flag = true;
			}
		}
		else {
			num = k;
			max = max < g ? g : max;
			flag = true;
		}

	}

	if (!flag) cout << "-1";
	else cout << max << " " << num;
	
	return 0;
}