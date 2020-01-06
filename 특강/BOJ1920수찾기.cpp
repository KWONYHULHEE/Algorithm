#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100010];

int main() {


	int n, m, k;


	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &k);

		if (binary_search(arr, arr + n, k))
			printf("1\n");

		else
			printf("0\n");


	}


	return 0;
}
