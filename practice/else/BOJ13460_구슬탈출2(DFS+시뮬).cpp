#include<iostream>
#include<algorithm>

using namespace std;

struct Pt{
	int y;
	int x;
};

const int MAX_TRY = 10;
const int INF = 987654321;
//상하좌우
const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

int N, M;	//세로, 가로
char MAP[10][10];
Pt R, B, O;

int solve(int cnt, Pt r, Pt b, int dir) {

	if (cnt > MAX_TRY) {
		return INF;
	}

	int ry = r.y;
	int rx = r.x;
	int by = b.y;
	int bx = b.x;

	int res = INF;
	if (dir != -1) {
		while (MAP[ry + dy[dir]][rx + dx[dir]] == '.') {
			ry += dy[dir];
			rx += dx[dir];
			if (ry == O.y && rx == O.x) { //빨간공이 들어가면
				res = cnt; //갱신
				break;
			}
		}
		while (MAP[by + dy[dir]][bx + dx[dir]] == '.') {
			by += dy[dir];
			bx += dx[dir];
			if (by == O.y && bx == O.x) {//파란공이 들어가면
				return res = INF;// 불가능
			}
		}
		if (res != INF) return res; //구멍에 들어갔으면 

		//움직임이 없을때 return;
		if (ry == r.y && rx == r.x && by == b.y && bx == b.x) return res = INF;

		//겹쳤을 때
		if (ry == by && rx == bx) {
			if (dir == 0) {
				if (r.y < b.y) by++;
				else ry++;
			}
			else if (dir == 1) {
				if (r.y > b.y) by--;
				else ry--;
			}
			else if (dir == 2) {
				if (r.x < b.x) bx++;
				else rx++;
			}
			else if (dir == 3) {
				if (r.x > b.x) bx--;
				else rx--;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		res = min(res, solve(cnt + 1, { ry,rx }, { by,bx }, i));
	}

	return res;
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'R') {
				MAP[i][j] = '.';
				R.x = j;
				R.y = i;
			}
			else if (MAP[i][j] == 'B') {
				MAP[i][j] = '.';
				B.x = j;
				B.y = i;
			}
			else if (MAP[i][j] == 'O') {
				MAP[i][j] = '.';
				O.x = j;
				O.y = i;
			}
		}
	}

	int res = solve(0, R, B, -1);
	cout << (res == INF ? -1 : res) << endl;

	return 0;
}