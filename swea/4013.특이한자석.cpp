#include <stdio.h>
#include <algorithm>
using namespace std;
int test, k;
int arr[5][10];
bool check[10];


void rotate(int num, int dir) {

	if (dir == 1) {
		int temp = arr[num][8];
		for (int i = 8; i > 0; i--) {
			arr[num][i] = arr[num][i - 1];
		}
		arr[num][1] = temp;

	}
	else {
		int temp = arr[num][1];
		for (int i = 1; i < 8; i++) {
			arr[num][i] = arr[num][i + 1];
		}
		arr[num][8] = temp;
	}

}
void init() {
	check[1] = false;
	check[2] = false;
	check[3] = false;
	check[4] = false;
}
void solve(int num, int dir) {
	check[num] = true;
	//¿À¸¥ÂÊ
	if (num < 4 && !check[num + 1] && arr[num][3] != arr[num + 1][7]) {
		solve(num + 1, dir*-1);
	}
	//¿ŞÂÊ
	if (num > 1 && !check[num - 1] && arr[num - 1][3] != arr[num][7]) {
		solve(num - 1, dir*-1);
	}

	rotate(num, dir);

}
int main() {
	int total = 0;
	scanf("%d", &test);
	for (int p = 0; p < test; p++) {
		scanf("%d", &k);

		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 8; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		for (int q = 0; q < k; q++) {
			int num, dir;
			scanf("%d %d", &num, &dir);
			solve(num, dir);
			init();
		}

		for (int i = 1; i <= 4; i++) {
			if (arr[i][1] == 1) {
				total += pow(2, i - 1);
			}
		}
		printf("#%d %d\n", p + 1, total);
		total = 0;
	}



	return 0;
}