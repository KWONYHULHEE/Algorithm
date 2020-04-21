#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
#include <string>
using namespace std;

int n;
int arr[60][60];
int check[60][60];
queue <pair<int, int>>q;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string S; cin >> S;
		for (int j = 0; j < S.length(); j++)
		{
			arr[i][j] = S[j] - '0';
			check[i][j] = 987654321;
		}
	}


	q.push({ 0,0 });
	check[0][0] = 0;

	while (!q.empty()) {

			int x = q.front().first;
			int y = q.front().second;
			q.pop();


			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

				if (arr[nx][ny] == 0) {
					if (check[nx][ny] > check[x][y] + 1) {
						check[nx][ny] = check[x][y] + 1;
						q.push({ nx,ny });
					}
				}
				else {
					if (check[nx][ny] > check[x][y]) {
						check[nx][ny] = check[x][y];
						q.push({ nx,ny });
					}
				}	
			}
		
	}

	cout << check[n-1][n-1]<<"\n";

	return 0;
}

