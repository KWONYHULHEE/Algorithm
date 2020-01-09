
/*

 ����� �ȵǴ� �μ� - > �μ��� �ִ������� 1


*/

#include<stdio.h>
int ans[1001] = { 0,2 };  //1���� 2��

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{

	for (int i = 2; i <= 1000; i++)
	{
	
		int n = 0;
		for (int j = 1; j <= i; j++)  //2,1 ����
		{
			if (gcd(i, j) == 1)
				n++;
		}
		ans[i] = ans[i - 1] + n;
	}

	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n] * 2 - 1);
	}
}

