#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int tc;
int m, n, k;
int arr[60][60];
bool check[60][60];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void solve(int x, int y) {

	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] != 1 || check[nx][ny]) continue;

		solve(nx, ny);
	}
}

int main() {



	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		memset(check, false, sizeof(check));
		memset(arr, false, sizeof(arr));
		int cnt = 0;
		cin >> n >> m >> k;


		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!check[i][j] && arr[i][j] == 1) {
					solve(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}



	return 0;
}