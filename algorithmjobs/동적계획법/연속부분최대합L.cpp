#include <stdio.h>
const int MAX = 1000010;

int arr[MAX];
int d[MAX];
int n;

int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	d[0] = arr[0];
	for (int i = 1; i < n; i++) {
		if (d[i - 1] + arr[i] < arr[i])
			d[i] = arr[i];
		else
			d[i] = d[i - 1] + arr[i];
	}

	int max = -1231135;
	for (int i = 0; i < n; i++) {
		if (max < d[i])
			max = d[i];
	}

	printf("%d", max);
	return 0;
}