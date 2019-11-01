#include <stdio.h>
int n;
int res[30];
int cnt = 0;

void division(int x, int sum) {

	if (sum == n) {

		for (int i = 0; i < x - 1; i++) {
			if (res[i] < res[i + 1]) return;
		}

		cnt++;
		for (int i = 0; i < x - 1; i++) {
			printf("%d+", res[i]);
		}
		printf("%d", res[x - 1]);
		printf("\n");

	}
	else if (x <= n && sum < n) {
		for (int i = n - 1; i > 0; i--) {
			res[x] = i;
			division(x + 1, sum + i);
		}
	}

}
int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);
	division(0, 0);
	printf("%d", cnt);
	return 0;
}