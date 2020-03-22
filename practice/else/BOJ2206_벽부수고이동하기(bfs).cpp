#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;


int n, m;
bool check[1010][1010][2];
int arr[1010][1010];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };


int bfs() {

	queue <pair<pair<int, int>, pair<int, int>>>q;

	check[0][0][0] = true;
	q.push({{ 0,0 }, { 1,0 }});

	while (!q.empty()) {
		
			int x = q.front().first.first;
			int y = q.front().first.second;
			int cnt = q.front().second.first;
			int flag = q.front().second.second;
			q.pop();

			if (x == n - 1 && y == m - 1) return cnt;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m|| check[nx][ny][flag]) continue;

				if (arr[nx][ny] == 1 && flag == 0) {
						check[nx][ny][flag+1] = true;
						q.push({ {nx,ny},{cnt+1,flag+1} });
				}
				else if(arr[nx][ny]==0){
					check[nx][ny][flag] = true;
					q.push( {{nx,ny},{cnt+1,flag}});
				}
			}
	}
	return -1;
}




int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	
	cout<<bfs();

	
	return 0;
}