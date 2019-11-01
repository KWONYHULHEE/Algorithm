#include <stdio.h>

int main() {

	int n, m;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;

	scanf("%d %d", &n, &m);


	for (int i = 1; i <= n; i++) {
		int temp = i;
		while (temp % 2 == 0) {
			a++;
			temp /= 2;
		}

		while (temp % 5 == 0) {
			b++;
			temp /= 5;
		}
	}

	for (int i = 1; i <= m; i++) {
		int temp = i;
		while (temp % 2 == 0) {
			c++;
			temp /= 2;
		}

		while (temp % 5 == 0) {
			d++;
			temp /= 5;
		}
	}
	for (int i = 1; i <= n - m; i++) {
		int temp = i;
		while (temp % 2 == 0) {
			e++;
			temp /= 2;
		}

		while (temp % 5 == 0) {
			f++;
			temp /= 5;
		}
	}

	int two = a - (c + e);
	int five = b - (d + f);

	int res = two < five ? two : five;
	printf("%d", res);




	return 0;
}