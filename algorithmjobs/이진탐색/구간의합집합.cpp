#include <stdio.h>
int n;
int num[20010];
long long int m;

bool check(long long int x) {
	int s = 1;
	int e = 2;

	long long int sum = 0;

	while (e <= 2 * n) {

		if (num[s] > x)
			sum += 0;
		else if (num[e] < x)
			sum += (num[e] - num[s] + 1);
		else
			sum += (x - num[s] + 1);

		s += 2;
		e += 2;

	}

	if (sum <= m)
		return false;
	else
		return true;
}
int main() {

	scanf("%d", &n);

	for (int i = 1; i <= 2 * n; i++)
		scanf("%d", &num[i]);


	scanf("%lld", &m);

	long long int s = 0;
	long long int e = 10000000000000;
	long long int mid;

	while (s + 1 < e) {
		mid = (s + e) / 2;
		if (!check(mid)) s = mid;
		else e = mid;
	}

	printf("%lld", e);

	return 0;
}