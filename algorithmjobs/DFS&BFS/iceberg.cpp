#include <iostream>
#include <string.h>
using namespace std;


int n, m;
int arr[310][310];
int str[310][310];
bool check2[310][310];
int cnt = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = { -1,1,0,0 };

void divide(int x, int y) {
	
	check2[x][y] = true;

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m || check2[nx][ny] || arr[nx][ny]==0) continue;

		divide(nx, ny);
	}

}
void melt(int x, int y) {


	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny]!=0) continue;
		if (str[x][y] <= 0) break;
		
		str[x][y]--;
	}


}
int main() {
	
	cin >> n >> m;
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			str[i][j] = arr[i][j];
		}
	}
	
	int time = 0;

	while (1) {
		
		memset(check2, false, sizeof(check2));
		cnt = 0;

		for (int i = 0; i < n; i++) {  //몇개로 분리됬는지 확인
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0 && !check2[i][j]) {
					divide(i, j);
					cnt++;
				}
			}
		}

		if (cnt >= 2) break;  //2개이상으로 분리됬으면 종료
		if (cnt == 0) { //다 0 이면 0출력
			cout << "0" << "\n";
			return 0;
		}


		for (int i = 0; i < n; i++) {  //녹이기 
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					melt(i, j);
				}
			}
		}
		
		time++;

		for (int i = 0; i < n; i++) {  //녹인거 업데이트
			for (int j = 0; j < m; j++) {
				arr[i][j] = str[i][j];
			}
		}

	}

	cout << time;

	return 0;
}
