#include <stdio.h>
int n;
bool check[100];
int res[100];
bool one = false;

bool ispossible(int x, int len) {

	for (int i = 0; i < len; i++) {
		if (res[x - i] != res[x - i - len])
			return true;
	}
	return false;

}
void goodseq(int x) {


	if (x == n) {
		if (one == true) return;

		one = true;
		for (int i = 0; i < x; i++) {
			printf("%d", res[i]);
		}
		printf("\n");
	}
	else if (one == true) return;

	else {
		for (int i = 1; i <= 3; i++) {
			res[x] = i;
			bool flag = true;

			for (int j = 1; j <= (x + 1) / 2; j++) {
				if (!ispossible(x, j)) {
					flag = false;
					break;
				}
			}

			if (flag == true)
				goodseq(x + 1);
		}
	}
}

int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);

	goodseq(0);

	return 0;
}