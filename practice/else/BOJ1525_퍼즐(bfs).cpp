#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <cstdio>

using namespace std;

string puzzle;
int nextx[4] = { -1,1,-3,3 };
queue<string> q;
int num=-1;
set<string> s;
bool flag = true;

void bfs() {
	int a;
	q.push(puzzle);
	s.insert(puzzle);

	while (!q.empty()) {

		int size = q.size();
		num++;

		while(size--) {

			string cur = q.front();
			q.pop();

			if (cur == "123456780") {
				flag = false;
				return;
			}

			for (int i = 0; i < 9; i++)
				if (cur[i] == '0') {
					a = i;
					break;
				}

			for (int i = 0; i < 4; i++) {
				int x = a + nextx[i];

				if (x < 0 || (a % 3 == 0 && i == 0) || (a % 3 == 2 && i == 1) || x >= 9) // ������ ��� ���� 
					continue;

				else {
					string cp = cur; //���ڿ� swap 
					swap(cp[x], cp[a]);
					if (s.count(cp) == 0) {
						s.insert(cp);
						q.push(cp);
					}
				}
			}

			
		}
		
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++) {
		char a;
		cin >> a;
		puzzle += a;
	}

	bfs();
	if (flag) //flag�� true�̸� ���ڿ��� �ϼ����� ���Ѱ�� 
		cout << -1;
	else
		cout << num;
	return 0;
}