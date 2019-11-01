#include <stdio.h>

int main() {

	//Please Enter Your Code Here
	int n;
	int arr[110][110] = { 0, };


	scanf("%d", &n);
	for (int t = 1; t <= n; t++) {

		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		for (int i = a; i < a + c; i++) {
			for (int j = b; j < b + d; j++) {
				arr[i][j] = t;
			}
		}
	}

	for (int t = 1; t <= n; t++) {
		int tot = 0;
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				if (arr[i][j] == t) tot++;
			}
		}
		printf("%d\n", tot);
	}
	// for(int i=0;i<20;i++){
	//     for(int j=0;j<20;j++){
	//       printf("%d ",arr[i][j]);
	//     }
	//     printf("\n");
	// }
	return 0;
}



