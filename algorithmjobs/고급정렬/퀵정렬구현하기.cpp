#include <stdio.h>

int getLeft(int arr[], int start, int end, int pivot, int result[]) {

	int idx = 0;
	for (int i = start; i <= end; i++) {
		if (arr[i] <= pivot) {
			result[idx++] = arr[i];
		}
	}
	return idx;
}

int getRight(int arr[], int start, int end, int pivot, int result[]) {

	int idx = 0;
	for (int i = start; i <= end; i++) {
		if (arr[i] > pivot) {
			result[idx++] = arr[i];
		}
	}
	return idx;
}

void quicksort(int arr[], int start, int end) {

	if (start >= end)
		return;

	int pivot = arr[start];
	int left[100010]; int right[100010];

	int left_cnt = getLeft(arr, start + 1, end, pivot, left);
	int right_cnt = getRight(arr, start + 1, end, pivot, right);


	for (int i = 0; i < left_cnt; i++) {
		arr[start + i] = left[i];
	}

	arr[start + left_cnt] = pivot;
	for (int i = 0; i < right_cnt; i++) {
		arr[start + left_cnt + 1 + i] = right[i];
	}

	quicksort(arr, start, start + left_cnt - 1);
	quicksort(arr, start + left_cnt + 1, end);


}

int main() {

	//Please Enter Your Code Here

	int arr[100010];
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	quicksort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}