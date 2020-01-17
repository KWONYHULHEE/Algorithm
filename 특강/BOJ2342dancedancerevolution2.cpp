#include <iostream>
#include <algorithm>
#define MAX 99999999
#pragma warning(disable:4996)
using namespace std;

int n, ddr[100001], dp[5][5][100001];

int from_to(int p1, int p2)
{
	if (p1 == 0)
		return 2;
	if (abs(p1 - p2) == 2)
		return 4;
	return 3;
}

int moving(int pre, int next, int cur)
{
	if (ddr[cur] == 0)
		return 0;

	int& ret = dp[pre][next][cur];
	if (ret) return ret;


	if (next == ddr[cur] || pre == ddr[cur])
		ret = moving(pre, next, cur + 1) + 1;
	else
	{
		ret = from_to(pre, ddr[cur]) + moving(ddr[cur], next, cur + 1);
		ret = min(ret, from_to(next, ddr[cur]) + moving(pre, ddr[cur], cur + 1));
	}
	return ret;
}

int main()
{
	n = 0;
	while (1)
	{
		scanf("%d", &ddr[n++]);
		if (ddr[n - 1] == 0)
			break;
	}
	printf("%d", moving(0, 0, 0));
}
