#include <stdio.h>
int n, m, q;
const int MAX = 1100;
int arr[MAX][MAX];
int total[MAX][MAX];

int main() {

	//Please Enter Your Code Here
	scanf("%d %d %d", &n, &m, &q);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	total[1][1] = arr[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			total[i][j] = total[i - 1][j] + total[i][j - 1] + arr[i][j] - total[i - 1][j - 1];
		}
	}

	for (int k = 0; k < q; k++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		int res = total[c + 1][d + 1] - total[c + 1][b] - total[a][d + 1] + total[a][b];
		printf("%d\n", res);
	}
	return 0;
}
