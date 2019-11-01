#include <stdio.h>
#include <string.h>
char arr[3][10000];
int str[3][10000];
int main() {

	//Please Enter Your Code Here

	int total = 0;
	int value = 0;
	int cnt = 0;

	scanf("%s", arr[1]);
	scanf("%s", arr[2]);


	int alen = strlen(arr[1]);
	int blen = strlen(arr[2]);
	if (alen == blen) {
		for (int i = 0; i < alen; i++) {
			if (arr[1][i] == arr[2][i])
				cnt++;
		}
		if (cnt == alen) {
			printf("0");
			return 0;
		}

	}

	int max = alen > blen ? 1 : 2;
	int min = alen > blen ? 2 : 1;

	int maxlen = alen > blen ? alen : blen;
	int minlen = alen > blen ? blen : alen;

	int k = maxlen - 1;

	for (int i = 0; i < maxlen; i++) {
		str[1][i] = arr[max][k--] - '0';
	}
	k = minlen - 1;

	for (int i = 0; i < minlen; i++) {
		str[2][i] = arr[min][k--] - '0';
	}

	for (int i = 0; i < maxlen; i++) {
		total = str[1][i] - str[2][i] - value;
		value = 0;

		if (total < 0) {
			value++;
			total += 10;
		}

		str[3][i] = total;
	}

	int m = maxlen;

	while (1) {
		if (str[3][m] != 0)
			break;
		else
			m--;
	}





	if (max != 1)
		printf("-");
	for (int i = m; i >= 0; i--)
		printf("%d", str[3][i]);

	return 0;
}