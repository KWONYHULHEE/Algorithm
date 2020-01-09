#include <cstdio>
using namespace std;
/*
	�켱 A�� ������� �� ������ ��,
	B�� ����� �ϳ��� �����鼭 A�� ������ ���� �񱳸� �� �ش�.
	B�� ����� A�� ����� �ִ������� ���ؼ� �� ������ �����ְ�,
	�� ����� ��� �ִ������� ������.
*/

long gcd(long a, long b) {

	return b == 0 ? a : gcd(b, a%b);
}


int main()
{
	int n, m;
	int a[1001];
	int i, j, k, t, b = 0;
	long long s;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	scanf("%d", &m);
	s = 1;
	for (j = 0; j < m; j++)
	{
		scanf("%d", &k);
		for (i = 0; i < n; i++)
		{
			if (a[i] != 1)
			{
				t = gcd(a[i], k);
				s = s * t;
				if (s >= 1000000000) {
					s %= 1000000000; 
					b = 1; 
				}
				k /= t;
				a[i] /= t;

				if (k == 1)break;
			}
		}
	}


	if (b==1) printf("%09lld\n", s);
	
	else printf("%lld\n", s);


	return 0;
}