#include <stdio.h>
int n;
int t[110];
int sum = 0;


int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);
	t[1] = 1;
	t[2] = 2;

	for (int i = 3; i <= n; i++) {
		sum = t[i - 1] + t[i - 2];
		t[i] = sum % 1000007;
	}
	printf("%d", t[n]);
	return 0;
}