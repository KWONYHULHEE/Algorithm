#include <cstdio>
using namespace std;
int arr[1010][1010];
int main() {


	int n, k;


	scanf("%d %d", &n, &k);

	for (int i = 0; i <= n + 1; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	for (int i = 2; i <= n + 1; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			arr[i][j] %= 10007;
		}
	}

	/*

	for (int i = 0; i < 50; i++) {
	for (int j = 0; j < 50; j++) {
	printf("%d ",arr[i][j]);
	}
	printf("\n");
	}
	*/
	printf("%d\n", arr[n][k]);




	return 0;
}