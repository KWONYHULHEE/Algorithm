#include <cstdio>
using namespace std;


int main() {

	long long int X, Y;
	long long int Z=0;
	scanf("%lld %lld", &X, &Y);

	Z = (Y * 100) / X;

	if (Z >= 99) {
		printf("-1");
	}
	else {
		long long int tmp1 = X * (Z + 1) - (100 * Y);
		long long int tmp2 = 99 - Z;
		printf("%lld", (tmp1 % tmp2) > 0 ? (tmp1 / tmp2) + 1 : (tmp1 / tmp2));
	}


	return 0;
}


