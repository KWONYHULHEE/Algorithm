#include <stdio.h>
int arr[10][10];
int res = 100;
int count[6];

void copy(int copy[10][10], int str[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			copy[i][j] = str[i][j];
		}
	}

}
bool checkpaper(int x, int y, int k, int str[10][10]) {
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if (i >= 10 || j >= 10) return false;
			if (str[i][j] == 0) return false;
		}
	}
	return true;
}
void cover(int x, int y, int k, int copy[10][10]) {
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			copy[i][j] = 0;
		}
	}
}
void solve(int arr[10][10], int cnt) {

	if (cnt >= res) return;
	int x, y;
	bool flag = false;
	for (int i = 0; i < 10; i++) {    //1을 찾는당
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 1) {
				flag = true;
				x = i;
				y = j;
				break;
			}
		}
		if (flag) break;
	}
	if (!flag) { //1없으면 끝
		if (res > cnt) res = cnt;
		return;
	}
	for (int i = 5; i >= 1; i--) {
		if (count[i] == 0) continue;
		if (!checkpaper(x, y, i, arr)) continue;

		count[i]--;
		int newpaper[10][10];  //원본 건드리면 안되니까 
		copy(newpaper, arr);
		cover(x, y, i, newpaper);
		solve(newpaper, cnt + 1);
		count[i]++;
	}

}
int main() {

	//Please Enter Your Code Here
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= 5; i++) count[i] = 5;

	res = 100;
	solve(arr, 0);

	if (res == 100) res = -1;
	printf("%d", res);
	return 0;
}