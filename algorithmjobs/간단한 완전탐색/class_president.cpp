#include <stdio.h>

int main() {

	//Please Enter Your Code Here
	int n;
	int arr[1010][10];

	scanf("%d", &n);
	int cnt[1010] = { 0, };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) { //학생
		for (int j = 1; j <= n; j++) { //다른학생
			for (int k = 1; k <= 5; k++) { //학년
				if (i != j)
					if (arr[i][k] == arr[j][k]) {
						cnt[i]++;
						break;
					}
			}
		}
	}

	int max = -1;
	int student = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] > max)
		{
			max = cnt[i];
			student = i;
		}
	}
	printf("%d", student);

	return 0;
}