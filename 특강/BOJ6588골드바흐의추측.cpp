#include <cstdio>
using namespace std;

int arr[1000010] = { 0, };

int main() {


	int n;

	arr[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		for (int j = 2; j <= 1000000 / i; j++) {
			arr[i*j] = 1;
		}
	}// 소수 check   소수면 0
	

	while (1) {
		bool flag = false;
		scanf("%d", &n);
		if (n == 0) break;

		for (int i = n - 1; i > 0; i--) {

			if (arr[i] == 0 && (i % 2) != 0) {
				if (arr[n - i] == 0 && (n - i) % 2 != 0) {
					printf("%d = %d + %d\n", n, n - i, i);
					flag = true;
					break;
				}
			}
		}

		if (flag == false) printf("Goldbach's conjecture is wrong.\n");

	}


	return 0;
}