#include <cstdio>
#include <queue>
using namespace std;

struct Robot {
	int x, y, dir, cnt;
};


const int MAX = 110;
int n, m;
int arr[MAX][MAX];
int sx, sy, sd;
int ex, ey, ed;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int changedir(int k, int dir) {
	int d = 0;
	if (k == 1) {
		if (dir == 0) d = 3;
		else if (dir == 3) d = 1;
		else if (dir == 1) d = 2;
		else if (dir == 2) d = 0;
	}

	else if (k == 2) {
		if (dir == 0) d = 2;
		else if (dir == 2) d = 1;
		else if (dir == 1) d = 3;
		else if (dir == 3) d = 0;
	}
	return d;
}

void bfs(int x, int y, int d, int cnt) {
	bool check[MAX][MAX][4] = { 0, };
	queue <Robot> q;
	Robot s;
	s.x = x;
	s.y = y;
	s.dir = d;
	s.cnt = cnt;
	q.push(s);
	check[s.x][s.y][s.dir] = true;

	while (!q.empty()) {
		Robot cur;
		cur = q.front();
		q.pop();
		// printf("(%d,%d) %d    %d\n",cur.x,cur.y,cur.dir,cur.cnt);
		if (cur.x == ex && cur.y == ey && cur.dir == ed) {
			printf("%d", cur.cnt);
			return;
		}


		for (int i = 1; i <= 3; i++) {
			int nx = cur.x + dx[cur.dir] * i;
			int ny = cur.y + dy[cur.dir] * i;


			if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
			if (arr[nx][ny] == 1) break;

			if (!check[nx][ny][cur.dir]) {
				check[nx][ny][cur.dir] = true;
				q.push({ nx,ny,cur.dir,cur.cnt + 1 });
			}
		}


		for (int i = 1; i <= 2; i++) {
			int ndir = changedir(i, cur.dir);

			if (!check[cur.x][cur.y][ndir]) {
				q.push({ cur.x,cur.y,ndir,cur.cnt + 1 });
				check[cur.x][cur.y][ndir] = true;
			}
		}
	}
}

int main() {


	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	scanf("%d %d %d", &sx, &sy, &sd);
	scanf("%d %d %d", &ex, &ey, &ed);
	sx--;
	sy--;
	ex--;
	ey--;
	sd--;
	ed--;
	bfs(sx, sy, sd, 0);


	return 0;
}