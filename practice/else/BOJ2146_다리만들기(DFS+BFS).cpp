#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int arr[110][110];
int n;
int cnt = 1;
bool check[110][110];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y) {

	check[x][y] = true;
	arr[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n || check[nx][ny] || arr[nx][ny]==0) continue;
		
		dfs(nx, ny);
	}
}


int bfs(int num) {
	int res = 0;
	queue <pair<int, int>>q;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == num) {
				check[i][j] = true;
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		int size = q.size();
		res++;
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || check[nx][ny]) continue;

				if (arr[nx][ny]!=0 && arr[nx][ny] != num) return res;

				if (arr[nx][ny] == 0) {
					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && !check[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	int res = 987654321;

	for (int i = 1; i < cnt; i++) {
		memset(check, false, sizeof(check));
		res = min(res, bfs(i));
	}
	
	cout << res-1;
	return 0;
}