#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 1100;
int arr[MAX][MAX];
int check1[MAX][MAX];
int check2[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;


struct Point {
	int x;
	int y;
};

void bfs1(int a, int b) {
	bool check[MAX][MAX] = { 0, };
	queue <Point> q;
	int cnt1 = 0;
	Point p;
	p.x = a;
	p.y = b;
	q.push(p);
	check[a][b] = true;

	while (!q.empty()) {
		int size = q.size();
		cnt1++;
		while (size--) {

			Point current = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				Point next;
				next.x = current.x + dx[i];
				next.y = current.y + dy[i];

				if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;

				if (arr[next.x][next.y] == 1 && check[next.x][next.y] == false) {
					check[next.x][next.y] = true;
					check1[next.x][next.y] = cnt1;
				}

				else if (arr[next.x][next.y] == 0 && check[next.x][next.y] == false) {
					check[next.x][next.y] = true;
					q.push(next);

					if (next.x == 0 && next.y == m - 1)
						return;
				}
			}


		}
	}

}
void bfs2(int a, int b) {
	bool check3[MAX][MAX] = { 0, };
	queue <Point> q;
	int cnt2 = 0;
	Point p;
	p.x = a;
	p.y = b;
	q.push(p);
	check3[a][b] = true;

	while (!q.empty()) {
		int size = q.size();
		cnt2++;
		while (size--) {

			Point current = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				Point next;
				next.x = current.x + dx[i];
				next.y = current.y + dy[i];
				if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;

				if (arr[next.x][next.y] == 1 && check3[next.x][next.y] == false) {
					check3[next.x][next.y] = true;
					check2[next.x][next.y] = cnt2;
				}

				else if (arr[next.x][next.y] == 0 && check3[next.x][next.y] == false) {
					check3[next.x][next.y] = true;
					q.push(next);
				}
				if (next.x == n - 1 && next.y == 0)
					return;
			}


		}
	}


}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}



	bfs1(n - 1, 0);
	bfs2(0, m - 1);

	// for(int i=0;i<n;i++){
	//     for(int j=0;j<m;j++){
	//     printf("%d ",check1[i][j]);
	//     }
	//     printf("\n");
	//   }
	int min = 12345;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (min > (check1[i][j] + check2[i][j]) && check1[i][j] != 0 && check2[i][j] != 0) {
				min = check1[i][j] + check2[i][j];
			}
		}
	}

	printf("%d", min);
	return 0;
}