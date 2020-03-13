#include <iostream>
using namespace std;

int n, m, x, y, d;
int arr[100][100];
int res = 0;

int main() {
	
	cin >> n >> m;
	cin >> x >> y >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		int dx[] = { -1,0,1,0 };  //북동남서
		int dy[] = { 0,1,0,-1 };

		if (arr[x][y] == 0) { //1. 청소
			arr[x][y] = 2;
			res++;
		}

		//왼쪽으로 돌면서 청소할곳이 있는지 확인 
		int check = 0;
		for (int i = 0; i< 4; i++) {
			d = d - 1; //왼쪽방향
			if (d < 0) d = 3;

			int temp_x = x + dx[d]; 
			int temp_y = y + dy[d];

			if (arr[temp_x][temp_y] == 0) { //청소할곳있으면
				x = temp_x; //움직이고
				y = temp_y;
				check = 1; //1번으로 가기
				break;
			}
		}

		if (check == 1) continue; //1번으로가깅

		//청소할곳 없으면
		int temp_d = d - 2;   //뒤로가기
		if (temp_d == -2) temp_d = 2;
		if (temp_d == -1) temp_d = 3;

		x = x + dx[temp_d];
		y = y + dy[temp_d];


		//뒤로갔는데 벽이거나 청소되있으면 끝
		if (arr[x][y] == 1) break; 
	}
	cout << res;
	return 0;
}