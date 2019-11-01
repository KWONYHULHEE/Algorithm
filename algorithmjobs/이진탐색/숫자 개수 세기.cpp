#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[100000];
int str[100000];
int cnt[100000];

void binary(int arr[], int s, int e, int pivot) {
	if (s > e) return;
	else if (s == e) {
		if (arr[s] == pivot) cnt[pivot]++;
		else return;
	}
	else {
		int mid = (s + e) / 2;
		if (arr[mid] == pivot) {
			cnt[pivot]++;
			binary(arr, s, mid - 1, pivot);
			binary(arr, mid + 1, e, pivot);
		}
		else if (arr[mid] > pivot)  binary(arr, s, mid - 1, pivot);
		else binary(arr, mid + 1, e, pivot);
	}
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < q; i++) {
		scanf("%d", &str[i]);
	}
	sort(arr, arr + n);

	for (int i = 0; i < q; i++) {
		binary(arr, 0, n - 1, str[i]);
		printf("%d\n", cnt[str[i]]);
		cnt[str[i]] = 0;
	}


	return 0;
}













