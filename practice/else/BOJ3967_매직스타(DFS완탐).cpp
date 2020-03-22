#include <iostream>
#include <vector>
using namespace std;

vector <pair<int, int>>v;
char map[10][10];
bool check[30];
bool flag = false;

void solve(int cnt) {

	if (flag) return;

	if (cnt==v.size()) {

		if (map[0][4] + map[1][3] + map[2][2] + map[3][1] - 4 * 'A' + 4 != 26) return;
		if (map[0][4] + map[1][5] + map[2][6] + map[3][7] - 4 * 'A' + 4 != 26) return;
		if (map[3][1] + map[3][3] + map[3][5] + map[3][7] - 4 * 'A' + 4 != 26) return;
		if (map[1][1] + map[1][3] + map[1][5] + map[1][7] - 4 * 'A' + 4 != 26) return;
		if (map[1][1] + map[2][2] + map[3][3] + map[4][4] - 4 * 'A' + 4 != 26) return;
		if (map[1][7] + map[2][6] + map[3][5] + map[4][4] - 4 * 'A' + 4 != 26) return;
		
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}

		flag = true;
		return;
	}
	else {
		for (int i = 0; i < 12; i++) {
			if (!check[i]) {
				check[i] = true;
				map[v[cnt].first][v[cnt].second] = i + 'A';
				solve(cnt + 1);
				check[i] = false;
				map[v[cnt].first][v[cnt].second] = 'x';
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'x') v.push_back({ i,j });
			if('A' <= map[i][j] && map[i][j] <= 'L') check[map[i][j] - 'A'] = true;
		}
	}


	solve(0);


	return 0;
}