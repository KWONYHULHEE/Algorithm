#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int n, m, h;
const int MAX = 110;
int str[MAX][MAX][MAX];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

int cnt = 0;
struct Point {
	int x;
	int y;
	int z;
};
queue <Point> q;

bool istomato() {
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (str[i][j][k] == 0) return true;
			}
		}
	}
	return false;
}

void bfs() {

	while (!q.empty()) {
		int size = q.size();
		cnt++;
		while (size--) {
			Point current = q.front();
			q.pop();

			for (int i = 0; i < 6; i++) {
				Point next;
				next.x = current.x + dx[i];
				next.y = current.y + dy[i];
				next.z = current.z + dz[i];

				if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m || next.z < 0 || next.z >= h) continue;

				if (str[next.x][next.y][next.z] == 0) {
					str[next.x][next.y][next.z] = 1;
					q.push(next);
				}
			}
		}
	}
}

int main() {

	//Please Enter Your Code Here

	scanf("%d %d %d", &m, &n, &h);
	bool flag = false;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &str[i][j][k]);
				if (str[i][j][k] == 0)
					flag = true;
				if (str[i][j][k] == 1) {
					Point p;
					p.x = i;
					p.y = j;
					p.z = k;
					q.push(p);
				}
			}
		}
	}

	if (flag == false) {
		printf("0");
		return 0;
	}
	bfs();
	if (istomato() == true)
		printf("-1\n");

	else if (istomato() == false)
		printf("%d\n", cnt - 1);



	// for(int k=0;k<h;k++){
	//   for(int i=0;i<n;i++){
	//     for(int j=0;j<m;j++){
	//       printf("%d ",str[i][j][k]);
	//     }
	//     printf("\n");
	//   }
	// }
	return 0;

}