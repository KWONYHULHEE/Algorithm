#include <iostream>
using namespace std;

int n, m, x, y, k;
int arr[30][30];
int dice[7];


bool checkmap(int order) {

	bool flag = true;

	if (order == 1) {
		y++;
		if (y < 0 || y >= m) {
			y--;
			flag = false;
		}
	}
	else if (order == 2) {
		y--;
		if (y < 0 || y >= m) {
			y++;
			flag = false;
		}
	}
	else if (order == 3) {
		x--;
		if (x < 0 || x >= n) {
			x++;
			flag = false;
		}
	}
	else if (order == 4) {
		x++;
		if (x < 0 || x >= n) {
			x--;
			flag = false;
		}
	}

	if (!flag) return false;
	else return true;
}

void checkdice(int order) {

	if (order == 1) {
		int temp = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = temp;
	}
	else if (order == 2) {
		int temp = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = temp;
	}
	else if (order == 3) {
		int temp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = temp;
	}
	else if(order == 4) {
		int temp = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = temp;
 	}
}

int main() {
	
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int order;
		cin >> order;

		if (!checkmap(order)) continue; //범위벗어나면 다음으로, x,y위치조정

		checkdice(order); //주사위 위치조정
		if (arr[x][y] == 0) arr[x][y] = dice[6]; 
		else {
			dice[6] = arr[x][y];
			arr[x][y] = 0;
		}

		cout << dice[1] << "\n";

	}
	
	return 0;
}