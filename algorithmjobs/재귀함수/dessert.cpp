#include <stdio.h>
int arr[20];
int str[20];
int res[20];
int cnt = 0;
int n;
void dessert(int x) {

	if (x >= n - 1) {

		for (int i = 0; i < n; i++) {
			str[i] = i + 1;
		}

		for (int i = 0; i < n - 1; i++) {
			if (res[i] == 2) {
				for (int j = i; j >= 0; j--) {
					if (str[j] != 0) {
						if (arr[i + 1] >= 10) {
							str[j] = str[j] * 100 + str[i + 1];
							str[i + 1] = 0;
							break;
						}
						else {
							str[j] = str[j] * 10 + str[i + 1];
							str[i + 1] = 0;
							break;
						}
					}
				}
			}
		}

		int k = 1;
		int sum = str[0];
		for (int i = 0; i < x; i++) {
			if (res[i] == 0) {
				sum += str[k++];
			}
			else if (res[i] == 1)
				sum -= str[k++];
			else
				k++;
		}


		if (sum == 0)
		{
			cnt++;
			if (cnt > 20) return;

			for (int i = 0; i < n - 1; i++) {
				printf("%d ", arr[i]);
				if (res[i] == 0)
					printf("+ ");
				else if (res[i] == 1)
					printf("- ");
				else if (res[i] == 2)
					printf(". ");

			}
			printf("%d", arr[n - 1]);
			printf("\n");
		}

	}
	else {
		for (int i = 0; i < 3; i++) {
			res[x] = i;
			dessert(x + 1);
		}
	}
}

int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	dessert(0);
	printf("%d", cnt);
	return 0;
}