#include <stdio.h>

int res[50];
int n, r;
bool check[50];

void tobin(int x) {

	if (x >= r) {

		for (int i = 0; i < x; i++) {
			printf("%c", res[i]);
		}
		printf("\n");
	}
	else {

		for (int i = 0; i < n; i++) {
			char y = i + 'a';
			if (check[y] == false) {
				check[y] = true;
				res[x] = y;
				tobin(x + 1);
				check[y] = false;
			}
		}
	}




}
int main() {

	//Please Enter Your Code Here

	scanf("%d %d", &n, &r);
	tobin(0);
	return 0;
}