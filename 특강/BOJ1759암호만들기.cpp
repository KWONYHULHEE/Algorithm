#include <stdio.h>
#include <algorithm>
using namespace std;

int l, c;
int res[50];
char arr[50];

void dfs(int x, int y) {

	if (y == l) {
		int mo = 0;
		int ja = 0;

		for (int i = 0; i<y; i++) {
			if (arr[res[i]] == 'a' || arr[res[i]] == 'e' || arr[res[i]] == 'i' || arr[res[i]] == 'o' || arr[res[i]] == 'u')
				mo++;
			else
				ja++;
		}

		if (mo >= 1 && ja >= 2) {
			for (int i = 0; i<y; i++) {
				printf("%c", arr[res[i]]);
			}
			printf("\n");
		}
		else return;
	}

	else {
		for (int i = x; i<c; i++) {
			res[y] = i;
			dfs(i + 1, y + 1);
		}
	}

}


int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &l, &c);

	for (int i = 0; i<c; i++)
		scanf(" %c", &arr[i]);

	sort(arr, arr + c);
	dfs(0, 0);

	return 0;
}