#include <stdio.h>

int n;
long long int m;

int result(long long int m) {
	if (m == 0)
		return 1;
	else {
		if (m % 2 == 0) return result(m / 2)*result(m / 2) % 10007;
		else return result(m - 1)*n % 10007;
	}
}


int main() {


	scanf("%d %lld", &n, &m);
	int res = result(m);
	printf("%d", res);
	//Please Enter Your Code Here

	return 0;
}