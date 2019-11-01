#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
const int MAX = 100010;
int arr[MAX];
int d[MAX];
int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	d[0] = arr[0];
	d[1] = arr[0] + arr[1];
	d[2] = max(max(arr[0] + arr[1], arr[1] + arr[2]), arr[0] + arr[2]);

	for (int i = 3; i < n; i++) {

		d[i] = max(max(d[i - 3] + arr[i - 1] + arr[i], d[i - 2] + arr[i]), d[i - 1]);

	}
	int maxx = -1314134;


	for (int i = 0; i < n; i++) {
		if (maxx < d[i])
			maxx = d[i];
	}
	printf("%d", maxx);
	return 0;
}