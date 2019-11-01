#include <stdio.h>

int abs(int x) {
	return x < 0 ? -1 * x : x;

}

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);

}

int main() {

	//Please Enter Your Code Here
	int n, x, y, r;
	scanf("%d %d %d %d", &n, &x, &y, &r);



	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (x == i && y == j)
				printf("x ");
			else
			{
				printf("%d ", dist(x, y, i, j) <= r ? dist(x, y, i, j) : 0);
			}
		}
		printf("\n");
	}

	return 0;
}