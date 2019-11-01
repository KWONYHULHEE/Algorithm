#include <cstdio>
int res = 98765;
int arr[30][30];
int d, w, k;

void init() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			arr[i][j] = 0;
		}
	}
}
void copy(int a[], int b[]) {

	for (int j = 0; j < w; j++)
		a[j] = b[j];


}
void cover(int x, int kind) {

	for (int j = 0; j < w; j++) {
		arr[x][j] = kind;
	}

}

bool check() {
	for (int i = 0; i < w; i++) {
		int value = 1;
		for (int j = 0; j < d - 1; j++) {
			if (value >= k) break;
			if (arr[j][i] == arr[j + 1][i]) {
				value += 1;
			}
			else value = 1;

		}
		if (value < k) return false;
	}
	return true;

}

void dfs(int x, int cnt) {

	if (x > d || res < cnt) return;
	if (check() == true) {
		if (res > cnt) res = cnt;
		return;
	}

	dfs(x + 1, cnt);

	int temp[30] = { 0, };
	copy(temp, arr[x]);
	cover(x, 0);
	dfs(x + 1, cnt + 1);
	copy(arr[x], temp);

	copy(temp, arr[x]);
	cover(x, 1);
	dfs(x + 1, cnt + 1);
	copy(arr[x], temp);

}
int main() {

	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		init();
		scanf("%d %d %d", &d, &w, &k);

		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		res = 98776;
		dfs(0, 0);
		printf("#%d %d\n", t, res);

	}



	return 0;
}