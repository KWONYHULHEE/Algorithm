#include <stdio.h>
const int MAX = 100010;
int arr[MAX][3];
int res[MAX][3];
int n;
int max = 0;
int maxx = 0;
int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	res[1][1] = arr[1][1];
	res[1][2] = arr[1][2];
	res[1][3] = arr[1][3];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			if (j == 1) {
				if (res[i - 1][2] > res[i - 1][3])
					max = res[i - 1][2];
				else
					max = res[i - 1][3];

				res[i][j] = max + arr[i][j];
			}
			else if (j == 2) {
				if (res[i - 1][1] > res[i - 1][3])
					max = res[i - 1][1];
				else
					max = res[i - 1][3];

				res[i][j] = max + arr[i][j];
			}
			else if (j == 3) {
				if (res[i - 1][1] > res[i - 1][2])
					max = res[i - 1][1];
				else
					max = res[i - 1][2];

				res[i][j] = max + arr[i][j];
			}
		}
	}

	for (int i = 1; i <= 3; i++) {
		if (maxx < res[n][i])
			maxx = res[n][i];
	}

	printf("%d", maxx);

	return 0;
}