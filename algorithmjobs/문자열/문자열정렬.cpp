#include <stdio.h>
#include <string.h>

int main() {

	char arr[110][110];
	char temp[110];
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0)
			{
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], temp);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", arr[i]);
	}
	return 0;
}
