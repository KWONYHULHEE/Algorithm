#include <stdio.h>
int n, k;
int res[40];

void tobin(int x, int cnt) {
	if (x == n) {
		if (cnt == k) {
			for (int i = 0; i < n; i++) {
				printf("%d", res[i]);
			}
			printf("\n");
		}
	}
	else if (x < n&&cnt <= k) {
		res[x] = 1;
		tobin(x + 1, cnt + 1);
		res[x] = 0;
		tobin(x + 1, cnt);

	}
}

int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &n, &k);
	tobin(0, 0);
	return 0;
}