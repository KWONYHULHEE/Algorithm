#include <stdio.h>
int arr[1000000];
int m, n;


bool check(int x) {
	long long int sum;

	for (int i = 0; i < n; i++) {
		if (arr[i] - x < 0)
			sum += 0;

		else sum += arr[i] - x;
	}
	if (sum >= m)
		return true;
	else return false;
}

int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int s = 1;
	int e = 1000000000;

	while (s + 1 < e) {
		int mid = (s + e) / 2;
		if (check(mid)) s = mid;
		else e = mid;
	}

	printf("%d", s);

	return 0;
}