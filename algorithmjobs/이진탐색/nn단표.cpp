#include <stdio.h>
long long int n, k;

bool check(long long int x) {
	long long int sum = 0;

	for (int i = 1; i <= n; i++) {
		if (x / i > n)
			sum += n;
		else
			sum += x / i;
	}

	if (sum < k) return true;
	else return false;
}



int main() {

	//Please Enter Your Code Here
	scanf("%lld %lld", &n, &k);

	long long int s = 0;
	long long int e = 10000000000;
	long long int mid = 0;

	while (s + 1 < e) {
		mid = (s + e) / 2;
		if (check(mid)) s = mid;
		else e = mid;
	}
	printf("%lld", e);
	return 0;
}