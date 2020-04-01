#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[5][10];
int temp[5][10];
int k;

void curving(int num, int cur) {
	if (cur == -1) {
		int tp = temp[num][1];
		temp[num][1] = temp[num][2];
		temp[num][2] = temp[num][3];
		temp[num][3] = temp[num][4];
		temp[num][4] = temp[num][5];
		temp[num][5] = temp[num][6];
		temp[num][6] = temp[num][7];
		temp[num][7] = temp[num][8];
		temp[num][8] = tp;
	}
	else if (cur == 1) {
		int tp = temp[num][1];
		temp[num][1] = temp[num][8];
		temp[num][8] = temp[num][7];
		temp[num][7] = temp[num][6];
		temp[num][6] = temp[num][5];
		temp[num][5] = temp[num][4];
		temp[num][4] = temp[num][3];
		temp[num][3] = temp[num][2];
		temp[num][2] = tp;
	}
}

void left(int num, int cur) {

	if (num < 1 || num>4) return;

	if (num - 1 >= 1 && num -1 <= 4 && (arr[num][7] != arr[num - 1][3])) {
		curving(num - 1, cur*(-1));
		left(num - 1, cur*(-1));
	}

}

void right(int num, int cur) {

	if (num < 1 || num>4) return;

	if (num + 1 <= 4 && num + 1 >= 1 && (arr[num][3] != arr[num + 1][7])) {
		curving(num + 1, cur*(-1));
		right(num + 1, cur*(-1));
	}
}



int main() {

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++) {
			scanf("%1d", &arr[i][j]);
			temp[i][j] = arr[i][j];
		}
	}
	cin >> k;

	for (int t = 0; t < k; t++) {
		int a, b;
		cin >> a >> b;
		left(a, b);
		right(a, b);
		curving(a, b);
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 8; j++) {
				arr[i][j] = temp[i][j];
			}
		}

	}
	int answer = 0;

	if (arr[1][1] == 1) answer += 1;
	if (arr[2][1] == 1) answer += 2;
	if (arr[3][1] == 1) answer += 4;
	if (arr[4][1] == 1) answer += 8;

	cout << answer;
	return 0;
}