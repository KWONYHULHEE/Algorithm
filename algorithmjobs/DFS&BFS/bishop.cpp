#include <stdio.h>
int n;
const int MAX = 20;
int arr[MAX][MAX];
int cnt1 = 0;
int cnt2 = 0;
bool d[MAX];
bool d2[MAX];
int res = 0; int res2 = 0;
void dfs_black(int x, int y) {
	cnt1++;

	if (res < cnt1) res = cnt1;

	d[x + y] = true;
	d2[x - y + n] = true;

	for (int i = x; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2 == 0) {
				if (arr[i][j] == 1 && (!d[i + j] && !d2[i - j + n])) {
					dfs_black(i, j);
				}
			}
		}
	}
	d[x + y] = false;
	d2[x - y + n] = false;
	cnt1--;


}
void dfs_white(int x, int y) {
	cnt2++;

	if (res2 < cnt2) res2 = cnt2;

	d[x + y] = true;
	d2[x - y + n] = true;

	for (int i = x; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2 == 1) {
				if (arr[i][j] == 1 && (!d[i + j] && !d2[i - j + n])) {
					dfs_white(i, j);
				}
			}
		}
	}
	d[x + y] = false;
	d2[x - y + n] = false;
	cnt2--;

}


int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && (i + j) % 2 == 0)
				dfs_black(i, j);
			else if (arr[i][j] == 1 && (i + j) % 2 == 1)
				dfs_white(i, j);
		}
	}

	printf("%d", res + res2);


	return 0;
}