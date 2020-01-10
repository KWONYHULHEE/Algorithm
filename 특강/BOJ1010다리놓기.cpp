#include <cstdio>
using namespace std;
int arr[50][50];
int main() {


	int tc;
	int n, k;

	scanf("%d", &tc);


	for (int i = 0; i <=30; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	for (int i = 2; i <= 30; i++) {
		for (int j = 1; j <=i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		
		}
	}


	for (int t = 1; t <= tc; t++) {
		int n, m;
		scanf("%d %d", &n, &m);

		printf("%d\n", arr[m][n]);
	}




	return 0;
}