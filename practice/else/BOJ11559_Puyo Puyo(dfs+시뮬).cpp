#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

char arr[12][6];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector <pair<int, int>> temp;
vector <pair<int, int>> temppop;
bool check[12][6];
int tempcnt = 0;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6 || check[nx][ny] || arr[nx][ny] == '.') continue;
		if (arr[x][y] != arr[nx][ny]) continue;
		tempcnt++;
		temp.push_back({ nx,ny });
		check[nx][ny] = true;
		dfs(nx, ny);
	}
}
void solution() {
	bool flag;
	int answer = 0;
	while (1) {
		flag = false;
		memset(check, false, sizeof(check));
		temppop.clear();

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] == '.' || check[i][j]) continue;
				tempcnt = 1;
				check[i][j] = true;
				temp.push_back({ i,j });
				dfs(i, j);

				if (tempcnt >= 4) {
					flag = true;
					for (int i = 0; i < temp.size(); i++) {
						temppop.push_back({ temp[i].first,temp[i].second });
					}
				}
				temp.clear();

			}
		}

		for (int i = 0; i < temppop.size(); i++) {
			arr[temppop[i].first][temppop[i].second] = '.';
		}

		for (int i = 10; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] == '.') continue;
				int tmp = i;

				while (1){
					if (tmp == 11 || arr[tmp + 1][j] != '.') break;

					arr[tmp + 1][j] = arr[tmp][j];
					arr[tmp][j] = '.';
					tmp++;
				}

			}
		}
		if (flag) answer++;
		else break;
	}
	cout << answer;

}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 6; j++){
			cin >> arr[i][j];
		}
	}

	solution();

	return 0;
}
