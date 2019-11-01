#include <stdio.h>

int main() {

	//Please Enter Your Code Here
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[110][110];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= m / 2 - 1; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[i][m - 1 - j];
			arr[i][m - 1 - j] = temp;
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}