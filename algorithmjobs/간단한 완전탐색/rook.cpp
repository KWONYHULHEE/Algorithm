#include <stdio.h>

int arr[10][10];

bool left(int x, int y) {

	for (int i = y - 1; i >= 1; i--) {
		if (arr[x][i] == 3) break;
		if (arr[x][i] == 2) return true;
	}

	return false;
}

bool right(int x, int y) {

	for (int i = y + 1; i <= 8; i++) {
		if (arr[x][i] == 3) break;
		if (arr[x][i] == 2) return true;
	}

	return false;
}

bool up(int x, int y) {

	for (int i = x - 1; i >= 1; i--) {
		if (arr[i][y] == 3) break;
		if (arr[i][y] == 2) return true;
	}

	return false;
}

bool down(int x, int y) {

	for (int i = x + 1; i <= 8; i++) {
		if (arr[i][y] == 3) break;
		if (arr[i][y] == 2) return true;
	}

	return false;
}



int main() {

	//Please Enter Your Code Here


	int x = 0;
	int y = 0;

	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				x = i;
				y = j;
			}
		}
	}

	if (right(x, y)) { printf("1"); return 0; }
	if (left(x, y)) { printf("1"); return 0; }
	if (up(x, y)) { printf("1"); return 0; }
	if (down(x, y)) { printf("1"); return 0; }
	printf("0");

	return 0;
}