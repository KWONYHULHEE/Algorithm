/*
1. 25ĭ�� 7ĭ�� �����Ѵ�
2. �̴ټ��İ� 4�� �̻����� üũ�Ѵ�
3. 2.�� ������Ų�ٸ� ���õ� 7ĭ�� ���� �������ִ��� üũ�Ѵ�
4. ���� ��� ������Ų�ٸ� Count!
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

int bfs() { //pick_7���� ���õ� 7ĭ�� �������ִ��� üũ
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

int yors() { //�̴ټ��İ� ������ ���ߴ��� üũ�ϴ� �Լ�
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

//25���߿��� 7�� ����
void pick_7(int d, int f) {

	if (f >= 25)return;
	if (d == 7) {  //7���������
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

