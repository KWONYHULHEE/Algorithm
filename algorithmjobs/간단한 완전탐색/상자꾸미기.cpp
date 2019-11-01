#include <stdio.h>

int main() {

	//Please Enter Your Code Here
	int arr[1010];
	int cnt[1010] = { 0, };
	int n;
	int sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		cnt[arr[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] > 2)
			cnt[i] = 2;


		sum += cnt[i];
	}

	if (sum >= 6)
		printf("YES");
	else
		printf("NO");

	return 0;
}