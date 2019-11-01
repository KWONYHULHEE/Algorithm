#include <stdio.h>

int main() {

	//Please Enter Your Code Here
	int n, m;
	scanf("%d %d", &n, &m);
	int x, y;
	int cnt = 0;
	scanf("%d %d", &x, &y);
	int dx[] = { -1,1,0,0,1,-1,-1,1 };
	int dy[] = { 0,0,1,-1,1,-1,1,-1 };

	int arr[110][110];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	if (arr[x - 1][y - 1] == 1)
	{
		printf("game over");
		return 0;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{

			if (arr[x - 1 + dx[i]][y - 1 + dy[i]] == 1 && x - 1 + dx[i] >= 0 && y - 1 + dy[i] >= 0)
				cnt++;
		}
	}

	printf("%d", cnt);




	return 0;
}