#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
};
vector <Point> start;
vector <Point> hole[10];
int n; int sx = 0; int sy = 0;
int arr[110][110];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int res = 0;
int changedir(int d, int value) {

	if (value == 1) {
		if (d == 0) return 1;
		else if (d == 1) return 3;
		else if (d == 2) return 0;
		else if (d == 3) return 2;
	}
	else if (value == 2) {
		if (d == 0) return 1;
		else if (d == 1) return 2;
		else if (d == 2) return 3;
		else if (d == 3) return 0;
	}
	else if (value == 3) {
		if (d == 0) return 2;
		else if (d == 1) return 0;
		else if (d == 2) return 3;
		else if (d == 3) return 1;
	}
	else if (value == 4) {
		if (d == 0) return 3;
		else if (d == 1) return 0;
		else if (d == 2) return 1;
		else if (d == 3) return 2;
	}
	else if (value == 5) {
		if (d == 0) return 1;
		else if (d == 1) return 0;
		else if (d == 2) return 3;
		else if (d == 3) return 2;
	}
}
void dfs(int x, int y, int dir, int cnt) {

	int a = x + dx[dir];
	int b = y + dy[dir];

	if (a < 0 || b < 0 || a >= n || b >= n) {
		int s = cnt * 2 + 1;
		if (res < s) res = s;
		return;
	}
	else if (a == sx && b == sy) {
		if (res < cnt) res = cnt;
		return;
	}
	else if (arr[a][b] == 0) dfs(a, b, dir, cnt);
	else if (arr[a][b] == -1) {
		if (res < cnt) res = cnt;
		return;
	}
	else if (arr[a][b] >= 1 && arr[a][b] <= 5) {
		dir = changedir(dir, arr[a][b]);
		dfs(a, b, dir, cnt + 1);
	}
	else if (arr[a][b] >= 6 && arr[a][b] <= 10) {
		int nx = hole[arr[a][b] - 6][0].x;
		int ny = hole[arr[a][b] - 6][0].y;
		if (nx == a && ny == b) {
			nx = hole[arr[a][b] - 6][1].x;
			ny = hole[arr[a][b] - 6][1].y;
		}
		dfs(nx, ny, dir, cnt);
	}

}
int main() {
	int tc;

	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		res = 0;
		start.clear();
		for (int i = 0; i < 10; i++)
			hole[i].clear();

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 0) start.push_back({ i,j });
				if (arr[i][j] >= 6 && arr[i][j] <= 10) hole[arr[i][j] - 6].push_back({ i,j });
			}
		}

		for (int i = 0; i < start.size(); i++) {
			sx = start[i].x;
			sy = start[i].y;
			for (int j = 0; j < 4; j++) {
				dfs(sx, sy, j, 0);
			}
		}
		printf("#%d %d\n", t, res);

	}

	return 0;
}