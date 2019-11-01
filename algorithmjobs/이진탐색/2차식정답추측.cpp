#include <stdio.h>
long long int a;


long long int cal(long long int x) {
	return x * x + x;
}

bool check(long long int x) {

	if (cal(x) <= a)
		return true;

	if (cal(x) > a)
		return false;
}

int main() {

	//Please Enter Your Code Here


	scanf("%lld", &a);

	long long int s = 0;
	long long int e = 1000000000;
	long long int mid = 0;


	while (s + 1 < e) {
		mid = (s + e) / 2;
		// printf("%d\n",mid);
		if (check(mid)) s = mid;
		else if (!check(mid)) e = mid;
	}

	printf("%d\n", s);
	// printf("%d",cal(316));
	return 0;
}