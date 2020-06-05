#include <cstring>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
bool check[10][10];
bool use[110];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int res = 0;
vector <pair<int, int >> v;

int find(int str[10][10]) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str[i][j] == 0) cnt++;
		}
	}
	return cnt;
}
void fill(int str[10][10], int x,int y) {

	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (check[nx][ny] || str[nx][ny] == 1) continue;

		if (str[nx][ny] == 0) {
			str[nx][ny] = 2;
			fill(str, nx, ny);
		}
	}

}
void copying(int a[10][10], int b[10][10]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = b[i][j];
		}
	}
}
void solve(int index, int cnt, int str[10][10]) {

	if (cnt == 3) {
		memset(check, false, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (str[i][j] == 2 && !check[i][j]) {
					fill(str, i, j);
				}
			}
		}
		int temp = find(str);
		if (res < temp) res = temp;
		return;
	}

	for (int i = index; i < v.size(); i++) {
		if (use[i]) continue;
		
		int copy[10][10] = { 0, };
		copying(copy, str);
		use[i] = true;
		copy[v[i].first][v[i].second] = 1;
		solve(i, cnt + 1, copy);
		use[i] = false;
	}
}

int main() {

	int arr[10][10];
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}

	solve(0, 0, arr);

	cout << res;
	return 0;
}