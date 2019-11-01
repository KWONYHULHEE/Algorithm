#include <stdio.h>
int arr[1010][1010];
int n, m;
int d[1010][1010];

int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int sum = 0;

	for (int j = 0; j < m; j++) {
		sum += arr[0][j];
		d[0][j] = sum;
	}
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i][0];
		d[i][0] = sum;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (d[i - 1][j] > d[i][j - 1])
				d[i][j] = d[i - 1][j] + arr[i][j];
			else
				d[i][j] = d[i][j - 1] + arr[i][j];
		}
	}

	// for(int i=0;i<n;i++){
	//   for(int j=0;j<m;j++){
	//     printf("%d ",d[i][j]);
	//   }
	//   printf("\n");
	// }

	printf("%d", d[n - 1][m - 1]);

	return 0;
}