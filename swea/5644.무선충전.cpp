#include <cstdio>
#include <algorithm>
using namespace std;

int M, A;
int a[110];
int b[110];
int str[15][15][10];
int tot = 0;

void check(int x, int y, int c, int k, int p) {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (abs(x - i) + abs(y - j) <= c) {
				str[j][i][k] = p;
			}
		}
	}
}
void init() {

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			for (int k = 0; k <= 10; k++) {
				str[i][j][k] = 0;
			}
		}
	}
}
void move() {


	int x1 = 1;
	int y1 = 1;
	int x2 = 10;
	int y2 = 10;
	int res = 0;

	for (int i = 1; i <= A; i++) {
		for (int j = 1; j <= A; j++) {
			int sum = 0;
			if (i == j)
				sum = str[y1][x1][i];
			else {
				sum = str[y1][x1][i] + str[y2][x2][j];
			}
			if (res < sum) res = sum;
		}
	}

	tot += res;

	for (int i = 1; i <= M; i++) {
		res = 0;
		if (a[i] == 1) y1--;
		else if (a[i] == 2) x1++;
		else if (a[i] == 3) y1++;
		else if (a[i] == 4) x1--;

		if (b[i] == 1) y2--;
		else if (b[i] == 2) x2++;
		else if (b[i] == 3) y2++;
		else if (b[i] == 4) x2--;

		for (int i = 1; i <= A; i++) {
			for (int j = 1; j <= A; j++) {
				int sum = 0;
				if (i == j && str[y1][x1][i] == str[y2][x2][j])
					sum = str[y1][x1][i];
				else {
					sum = str[y1][x1][i] + str[y2][x2][j];
				}
				if (res < sum) res = sum;
			}
		}
		tot += res;
	}



}
int main() {

	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		tot = 0;
		init();
		scanf("%d %d", &M, &A);

		for (int i = 1; i <= M; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= M; i++)
			scanf("%d", &b[i]);

		for (int i = 1; i <= A; i++) {
			int x, y, c, p;
			scanf("%d %d %d %d", &x, &y, &c, &p);

			check(x, y, c, i, p);
		}

		move();
		printf("#%d %d\n", t, tot);

	}
	return 0;
}