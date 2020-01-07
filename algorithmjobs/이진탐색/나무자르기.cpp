
#include <cstdio>
using namespace std;

long long int arr[1000010];
long long int m, n;


bool check(long long int x) {
	long long int sum=0;

	for (int i = 0; i < n; i++) {
		if (arr[i] - x < 0)
			sum += 0;

		else sum += arr[i] - x;
	}
	if (sum < m)
		return true;
	else return false;
}

int main() {

	long long int getmax = 0;
	//Please Enter Your Code Here
	scanf("%lld %lld", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		if (getmax < arr[i])
			getmax = arr[i];
	}

	long long int s = 0;
	long long int e = getmax;
	long long int mid = 0;

	while (s + 1 < e) {
		 mid = (s + e) / 2;
		if (check(mid)) e = mid;
		else s = mid;
	}

	printf("%lld\n", s);

	return 0;
}
