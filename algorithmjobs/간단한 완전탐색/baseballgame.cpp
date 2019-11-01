#include <stdio.h>

int main() {
	int k[110];
	int a = 0; int b = 0; int c = 0;
	int x = 0; int y = 0; int z = 0;
	int str[110]; int bal[110];
	int ok = 0;
	int n;
	int strike = 0; int ball = 0;
	int res = 0;
	scanf("%d", &n);

	//Please Enter Your Code Here

	for (int i = 101; i < 999; i++) {
		ok = 0;

		x = i / 100;
		y = (i % 100) / 10;
		z = (i % 100) % 10;

		if (x != 0 && y != 0 && z != 0 && x != y && y != z && x != z) {
			for (int j = 0; j < n; j++) {

				scanf("%d %d %d", &k[j], &str[j], &bal[j]);

				strike = 0;
				ball = 0;

				a = k[j] / 100;
				b = (k[j] % 100) / 10;
				c = (k[j] % 100) % 10;

				if (x == a)
					strike++;
				else if (x == b)
					ball++;
				else if (x == c)
					ball++;

				if (y == b)
					strike++;
				else if (y == a)
					ball++;
				else if (y == c)
					ball++;

				if (z == c)
					strike++;
				else if (z == a)
					ball++;
				else if (z == b)
					ball++;

				if (ball == bal[j] && strike == str[j])
					ok++;

			}
		}
		if (ok == n)
			res++;
	}

	printf("%d", res);


	return 0;
}