#include <stdio.h>
int n;
const int MAX = 100010;
int arr[MAX];
void merging(int arr[], int s1, int e1, int s2, int e2) {
	int temp[MAX];
	int p = s1;
	int q = s2;
	int idx = 0;

	while (p <= e1 && q <= e2) {
		if (arr[p] < arr[q]) {
			temp[idx++] = arr[p];
			p++;
		}
		else {
			temp[idx++] = arr[q];
			q++;
		}
	}

	if (p > e1) {
		for (int i = q; i <= e2; i++)
			temp[idx++] = arr[i];
	}
	else {
		for (int i = p; i <= e1; i++)
			temp[idx++] = arr[i];
	}

	for (int i = s1; i <= e2; i++) {
		arr[i] = temp[i - s1];
	}

}




void  mergesort(int arr[], int s, int e) {
	if (s >= e) return;

	int mid = (s + e) / 2;
	mergesort(arr, s, mid);
	mergesort(arr, mid + 1, e);

	merging(arr, s, mid, mid + 1, e);
}

int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	mergesort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}