#include <stdio.h>
#include <string.h>

int main() {

	int x, y;
	scanf("%d %d", &x, &y);

	int cnt = 0;
	int check = 1;
	int len = 0;
	int total = 0;
	len = y - x;



	while (len - check * 2 >= 0 && len != 0)
	{
		len = len - check * 2;
		check++; //거리증가
		cnt += 2; //횟수 증가

	}
	while (len - check >= 0 && len != 0)
	{
		len = len - check;
		check--;
		cnt++;
	}
	while (len - check < 0 && len != 0)
	{
		check = len;
		len = len - check;
		check--;
		cnt++;
	}



	printf("%d", cnt);
	return 0;
}