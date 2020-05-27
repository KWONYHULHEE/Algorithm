/*
1. 25칸중 7칸을 선택한다
2. 이다솜파가 4명 이상인지 체크한다
3. 2.를 만족시킨다면 선택된 7칸이 서로 인접해있는지 체크한다
4. 위를 모두 만족시킨다면 Count!
*/
#include<iostream>
#include<queue>

using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

int seven[27];
int visit[27];
char map[7][7];
int ret = 0;

int bfs() { //pick_7으로 선택된 7칸이 인접해있는지 체크
	fill(visit, visit + 27, 0);
	int cnt = 0;
	queue<int> q;
	int st;
	for (int i = 0; i < 25; i++) {
		if (seven[i] == 1) {
			st = i; break;
		}
	}
	q.push(st);
	visit[st] = 1;
	cnt++;

	while (!q.empty()) {

		int c = q.front();
		int cy = c / 5;
		int cx = c % 5;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			int nn = ny * 5 + nx;
			if (visit[nn] == 1 || ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || seven[nn] == 0) continue;
			visit[nn] = 1;
			q.push(nn);
			cnt++;

		}
	}
	return cnt;
}

int yors() { //이다솜파가 우위를 점했는지 체크하는 함수
	int cy = 0, cs = 0;

	for (int i = 0; i < 25; i++) {
		if (seven[i] == 0) continue;
		int y = i / 5;
		int x = i % 5;
		if (map[y][x] == 'S') cs++;
		else cy++;
	}

	if (cs >= 4) return true;
	else return false;
}

//25개중에서 7개 선택
void pick_7(int d, int f) {

	if (f >= 25)return;
	if (d == 7) {  //7개골랐으면
		if (yors()) {
			int connect = bfs();
			if (connect == 7) {
				ret++;
			}
		}
		return;
	}

	for (int i = f + 1; i < 25; i++) {
		seven[i] = 1;
		pick_7(d + 1, i);
		seven[i] = 0;
	}


}

int main() {

	for (int i = 0; i < 5; i++)
		cin >> map[i];

	pick_7(0, -1);
	cout << ret;

	return 0;
}

