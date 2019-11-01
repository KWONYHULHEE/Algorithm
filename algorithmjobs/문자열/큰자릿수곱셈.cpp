#include <stdio.h>
#include <string.h>

char a[10010];
char b[10010];
int res[10010];
int arr[2][10010];
int m = 0;

int main() {

	//Please Enter Your Code Here
	scanf("%s", a);
	scanf("%s", b);

	int alen = strlen(a);
	int blen = strlen(b);

	for (int i = alen - 1; i >= 0; i--) {
		arr[0][m++] = a[i] - '0';
	}
	m = 0;
	for (int i = blen - 1; i >= 0; i--) {
		arr[1][m++] = b[i] - '0';
	}

	for (int i = 0; i < blen; i++) {
		for (int j = 0; j < alen; j++) {
			res[i + j + 1] += (res[i + j] + arr[0][j] * arr[1][i]) / 10;
			res[i + j] = (res[i + j] + arr[0][j] * arr[1][i]) % 10;
		}
	}

	int k = alen * blen;

	while (res[k] == 0) {
		k--;
	}
	for (int i = k; i >= 0; i--) {
		printf("%d", res[i]);
	}

	return 0;
}