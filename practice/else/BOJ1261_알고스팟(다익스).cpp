#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, m;
int arr[110][110];
int dist[110][110];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
const int INF = 987654321;

void bfs(int x, int y) {

	queue <pair<int, int>> q;
	dist[x][y] = 0;
	q.push({ x,y });

	while (!q.empty()) {

			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;


				if (arr[nx][ny] == 1) {
					if (dist[nx][ny] > dist[x][y] + 1) {
						dist[nx][ny] = dist[x][y] + 1;
						q.push({ nx,ny });
					}
					
				}
				else{
					if (dist[nx][ny] > dist[x][y]) {
						dist[nx][ny] = dist[x][y];
						q.push({ nx,ny });
					}
				}
			}

	}


}
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++){
		string Inp;
		cin >> Inp;
		for (int j = 0; j < Inp.length(); j++){
			arr[i][j] = Inp[j] - '0';
			dist[i][j] = 987654321;
		}
	}


	bfs(0,0);
	cout << dist[m - 1][n - 1];
	
	return 0;

}

