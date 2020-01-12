#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
���ʺ��� gcd �� ����ϴ� �迭 �ϳ�

�����ʺ��� gcd �� ����ϴ� �迭 �ϳ�

���� arr[0]�� 8�� ���ٸ� rtol[1]�� �ִ������� �ȴ�.

���� arr[1]�� 12�� ���ٸ� gcd(ltor[0],rtol[2])�� �ִ������� �ȴ�.

��, �ش� ��ġ�� ���� �ִ������� ���� �ִ������� �ִ������� ��ü�� �ִ������� �ȴ�.



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