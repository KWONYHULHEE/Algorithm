#include <stdio.h>
#include <string.h>

char a[100010];
char b[100010];
int res[3][100010];
int str[100010];

int main() {

	//Please Enter Your Code Here
	scanf("%s", a);
	scanf("%s", b);

	int alen = strlen(a);
	int blen = strlen(b);
	int idx = 0;

	int max = alen > blen ? alen : blen;

	for (int i = alen - 1; i >= 0; i--) {
		res[0][idx++] = a[i] - '0';

	}
	idx = 0;
	for (int i = blen - 1; i >= 0; i--) {
		res[1][idx++] = b[i] - '0';
	}

	for (int i = 0; i < max; i++) {
		str[i + 1] += (str[i] + res[0][i] + res[1][i]) / 10;
		str[i] = (str[i] + res[0][i] + res[1][i]) % 10;
	}



	int k = max;
	while (str[max] == 0)
		max--;


	for (int i = max; i >= 0; i--) {
		printf("%d", str[i]);
	}

	return 0;
}