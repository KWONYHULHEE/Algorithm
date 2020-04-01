#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n,r,l;
int arr[110][110];
int arr2[110][110];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool check[110][110];
vector <pair<int, int>> v;
int sum = 0;

void calc(int x, int y) {

	check[x][y] = true;
	sum += arr[x][y];
	v.push_back({ x,y });

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n || check[nx][ny]) continue;

		if(abs(arr[x][y]-arr[nx][ny])>=r && abs(arr[x][y] - arr[nx][ny])<=l)
			calc(nx, ny);
			
	}

}


int main() {

	cin >> n >> r >> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int res = 0;

	while (1) { 

		bool flag = false;
		memset(check, false, sizeof(check));

		//국경 풀기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					calc(i, j);
					int val = sum / v.size();
					if (v.size() > 1) flag = true;
					for (int k = 0; k < v.size(); k++) {
						arr2[v[k].first][v[k].second] = val;
					}
					v.clear();
					sum = 0;
				}
			}
		}
		if (!flag) break;
		res++; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = arr2[i][j];
			}
		}
	
	}
	cout << res;
	return 0;
}