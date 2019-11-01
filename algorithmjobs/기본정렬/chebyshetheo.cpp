#include <stdio.h>
int arr[300000] = { 0, };
int main() {

	int n;
	int cnt = 0;
	for (int i = 2; i < 300000; i++) {
		for (int j = 2; j < 300000 / i; j++) {
			arr[i*j] = 1;
		}
	}

	while (1) {
		scanf("%d", &n);
		cnt = 0;
		if (n == 0)
			return 0;

		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] == 0)
				cnt++;
		}

		printf("%d\n", cnt);
	}


	return 0;
}

