#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int d[100010];

int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);

	d[1] = 1;

	for (int i = 2; i <= n; i++) {
		d[i] = 99999;

		int temp = sqrt(i);
		for (int j = 1; j <= temp; j++) {
			d[i] = min(d[i - j * j], d[i]);
		}
		d[i] += 1;
	}

	printf("%d", d[n]);

	return 0;
}