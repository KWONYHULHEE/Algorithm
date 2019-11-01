#include <stdio.h>

int gcd(int a, int b) {
	return a % b == 0 ? b : gcd(b, a%b);
}
int arr[100010];
int dist[100010];

int main() {

	//Please Enter Your Code Here

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < n; i++) {
		dist[i] = arr[i] - arr[i - 1];
	}

	int a = dist[1];
	for (int i = 2; i < n; i++) {
		a = gcd(a, dist[i]);
	}


	int res = ((arr[n - 1] - arr[0]) / a) + 1 - n;

	printf("%d", res);

	return 0;
}