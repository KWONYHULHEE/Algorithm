#include <stdio.h>

int main() {

	//Please Enter Your Code Here
	int arr[10][10];
	int str[300];
	int res = 0;
	int cnt = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < 25; i++)
		scanf("%d", &str[i]);


	for (int k = 0; k < 25; k++) {
		res = 0;
		int temp = str[k];

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (arr[i][j] == temp)
					arr[i][j] = 0;
			}
		}

		for (int i = 0; i < 5; i++) {
			cnt = 0;
			for (int j = 0; j < 5; j++) {
				if (arr[i][j] == 0)
					cnt++;
			}
			if (cnt == 5)
				res++;
		}

		for (int i = 0; i < 5; i++) {
			cnt = 0;
			for (int j = 0; j < 5; j++) {
				if (arr[j][i] == 0)
					cnt++;
			}
			if (cnt == 5)
				res++;
		}

		cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (arr[i][i] == 0)
				cnt++;
		}
		if (cnt == 5)
			res++;

		cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (arr[i][4 - i] == 0)
				cnt++;
		}
		if (cnt == 5)
			res++;


		if (res >= 3) {
			printf("%d", k + 1);
			return 0;
		}

	}

	return 0;
}