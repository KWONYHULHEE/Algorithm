#include <stdio.h>

int main() {

	//Please Enter Your Code Here
	int arr[30][30];
	int c, r;
	int max = 0;
	int cnt[30] = { 0, };
	int k = 0;
	int count = 0;
	int ok = 0;

	scanf("%d %d", &c, &r);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			if (arr[j][i] == 0) {
				cnt[i]++;
			}
			else break;
		}
	}


	max = cnt[0];
	for (int i = 1; i < c; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			k = i;
		}
	}

	if (max < 4) {
		printf("0 0");
		return 0;
	}
	// printf("%d %d",max,k);
	for (int i = max - 1; i >= max - 4; i--) {
		arr[i][k] = 1;
	}//테트리미노 삽입

	for (int i = 0; i < r; i++) {
		count = 0;
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 1)
				count++;
		}
		if (count == c)
			ok++;
	}
	if (ok == 0) {
		printf("0 0");
		return 0;

	}
	printf("%d %d", k + 1, ok);

	// for(int i=0;i<r;i++){
	//   for(int j=0;j<c;j++){
	//   printf("%d ",arr[i][j]);
	//   }
	//   printf("\n");
	// }

	return 0;
}