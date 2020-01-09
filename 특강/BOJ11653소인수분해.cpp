#include <cstdio>
#include <math.h>
using namespace std;


int main() {


	int n;
	scanf("%d", &n);

	for (int i = 2; i <= sqrt(n); i++) {
		while (n % i == 0) {
			printf("%d\n", i);
			n /= i;
		}
	}

	if (n != 1) printf("%d\n", n);

	return 0;
}