#include<iostream>
#include<queue>
using namespace std;

struct Obj {
	int x, y, dir, rotationNum;
};

int n, m;
int sx, sy, ex, ey;
char map[100][100];
int minRotationNum[100][100];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


void bfs() {

	queue<Obj> Q;
	minRotationNum[sx][sy] = 0;

	for (int i = 0; i < 4; i++)
		Q.push({sx,sy,i,0 });


	while (!Q.empty()) {
		int nowR = Q.front().x;
		int nowC = Q.front().y;
		int nowDir = Q.front().dir;
		int nowRotationNum = Q.front().rotationNum;

		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nextR = nowR + dx[i];
			int nextC = nowC + dy[i];
			int nextRotationNum = nowRotationNum;

			if (nextR < 0 || nextC < 0 || nextR >= n || nextC >= m || map[nextR][nextC] == '*')continue;

				if (i != nowDir) nextRotationNum++;

				if (minRotationNum[nextR][nextC] >= nextRotationNum) {
					minRotationNum[nextR][nextC] = nextRotationNum;
					Q.push({ nextR, nextC, i, nextRotationNum });
				}
			
		}
	}

}

int main() {

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			minRotationNum[i][j] = 987654321;
			if (!flag && map[i][j] == 'C') {
				flag = true;
				sx = i;
				sy = j;
			}
			else if(flag && map[i][j]=='C'){
				ex = i;
				ey = j;
			}
		}
	}

	bfs();

	cout << minRotationNum[ex][ey] << "\n";
	return 0;
}