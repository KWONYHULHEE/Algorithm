#include <stdio.h>

int binarysearch(int arr[], int start, int end, int value)
{
	if (start > end) return -1;
	else if (start == end)
	{
		if (arr[start] == value) return start;
		else return -1;
	}
	else
	{
		int mid = (start + end) / 2;

		if (arr[mid] == value) return mid;
		else if (arr[mid] < value)
			binarysearch(arr, mid + 1, end, value);
		else if (arr[mid] > value)
			binarysearch(arr, start, mid - 1, value);


	}
}

int main() {

	//Please Enter Your Code Here
	int n, q;
	int arr[100010];
	int str[100010];
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &str[i]);
	}
	for (int i = 0; i < q; i++)
	{
		int value = str[i];
		int idx = binarysearch(arr, 0, n - 1, value);
		if (idx == -1)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}