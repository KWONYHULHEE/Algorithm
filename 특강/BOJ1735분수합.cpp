#include <stdio.h>

long gcd(long a, long b) {

	if (b>a) return gcd(b, a);

	if (a%b == 0) return b;
	else  return gcd(b, a%b);
}


int main(void)
{
	long n1, n2, n3, n4, bottom = 0, top = 0, max = 0;

	scanf("%ld %ld", &n1, &n2);
	scanf("%ld %ld", &n3, &n4);

	bottom = n2 * n4;
	top = n1 * n4 + n3 * n2;

	max = gcd(top, bottom);
	top = top / max;
	bottom = bottom / max;

	printf("%ld %ld\n", top, bottom);
}
