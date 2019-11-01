#include <stdio.h>

int main() {

	//Please Enter Your Code Here
	int n, k;

	scanf("%d %d", &n, &k);
	int arr[100000];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < k; i++)
	{
		int inx = i;
		for (int j = i; j < n; j++)
		{
			if (arr[inx] < arr[j])
			{
				inx = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[inx];
		arr[inx] = temp;
	}


	printf("%d ", arr[k - 1]);
	return 0;
}