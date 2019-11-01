#include <stdio.h>

int main() {

	//Please Enter Your Code Here
	int arr[11];
	int sum = 0;
	int k = 10;
	int tot = 0;
	int max = 0;
	int bin = 0;
	int str[110] = { 0, };

	for (int i = 1; i <= 10; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
		str[arr[i] / 10]++;
	}

	for (int i = 1; i <= 100; i++)
	{
		if (max < str[i])
		{
			max = str[i];
			k = i;
		}
	}


	bin = k * 10;
	tot = sum / 10;
	printf("%d\n%d", tot, bin);

	return 0;
}