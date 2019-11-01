#include <stdio.h>
int n;
int t[100100];

int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);

	t[1] = 1;
	int sum = 0;

	for (int i = 2; i <= 3; i++) { //±âÀú
		sum += t[i - 1];
		t[i] = sum + 1;
	}

	for (int i = 4; i <= n; i++) {
		for (int j = i - 3; j <= i - 1; j++) {
			t[i] += t[j];
		}
		t[i] = t[i] % 1000007;
	}





	printf("%d", t[n]);
	return 0;
}