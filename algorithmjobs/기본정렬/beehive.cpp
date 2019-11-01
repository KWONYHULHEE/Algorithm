#include <stdio.h>

int arr[1000010];
int main() {

	//Please Enter Your Code Here
	int n;
	scanf("%d", &n);


	int k = 1;
	int inx = 6;
	for (int i = 1; i <= 1000000; i++) {
		arr[i] = k;
		k = k + inx * i;
	}


	for (int i = 1; i <= 1000000; i++) {
		if (arr[i] == n) { printf("%d", i); break; }
		if (arr[i]<n&&arr[i + 1]>n) { printf("%d", i + 1); break; }
	}

	return 0;
}