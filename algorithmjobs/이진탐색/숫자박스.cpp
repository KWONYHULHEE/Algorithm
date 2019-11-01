#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX = 500000;
int arr[MAX];
int str[MAX];
int n, m;

int binary(int arr[], int s, int e, int pivot) {
	if (s > e) return 0;
	else if (s == e) {
		if (arr[s] == pivot) return 1;
		else return 0;
	}

	int mid = (s + e) / 2;
	if (arr[mid] == pivot) return 1;
	else if (arr[mid] < pivot) return binary(arr, mid + 1, e, pivot);
	else return binary(arr, s, mid - 1, pivot);
}


int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);


	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
		scanf("%d", &str[i]);

	sort(arr, arr + n);

	for (int i = 0; i < m; i++) {
		int res = binary(arr, 0, n - 1, str[i]);
		printf("%d\n", res);
	}

	return 0;
}