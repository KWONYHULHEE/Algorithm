#include <stdio.h>
#include <queue>
using namespace std;

char arr[60][60];
int str[60][60];
int zzz[60][60];

int tot = 0;
int ok = 0;
int r, c;
int x, y, a, b;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int k = 0;
bool check1[60][60];

struct Point {
	int x;
	int y;
};
queue <Point> q;
void bfs() {

	while (!q.empty()) {
		int size = q.size();
		k++;
		while (size--) {
			Point current = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				Point next;
				next.x = current.x + dx[i];
				next.y = current.y + dy[i];

				if (str[next.x][next.y] == -1 || next.x < 0 || next.y < 0 || next.x >= r || next.y >= c || next.x == x && next.y == y) continue;

				if (zzz[next.x][next.y] == 60) {
					zzz[next.x][next.y] = k;
					q.push(next);
				}
			}
		}
	}
}
void bfs2(int n, int m) {
	queue <Point> q;
	bool check[60][60] = { 0, };
	Point p;
	p.x = n;
	p.y = m;
	q.push(p);
	check[n][m] = true;

	while (!q.empty()) {
		int size = q.size();
		tot++;
		while (size--) {
			Point current = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				Point next;
				next.x = current.x + dx[i];
				next.y = current.y + dy[i];

				if (next.x < 0 || next.y < 0 || next.x >= r || next.y >= c || tot >= zzz[next.x][next.y] || str[next.x][next.y] == -1) continue;

				if (check[next.x][next.y] == false && str[next.x][next.y] == 60) {
					check[next.x][next.y] = true;
					q.push(next);
				}

				if (next.x == x && next.y == y) {
					ok++;
					return;
				}
			}
		}
	}
}


int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &r, &c);
	int cnt = 0;
	for (int i = 0; i < r; i++)
		scanf("%s", arr[i]);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '.')
				str[i][j] = 60;
			else if (arr[i][j] == 'X')
				str[i][j] = -1;
			else if (arr[i][j] == '*') {
				str[i][j] = 1;
				Point p;
				p.x = i;
				p.y = j;
				q.push(p);
				cnt++;
			}
			else if (arr[i][j] == 'D') {
				x = i;
				y = j;
			}
			else if (arr[i][j] == 'S') {
				a = i;
				b = j;
			}
		}
	}


	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			zzz[i][j] = str[i][j];
		}
	}


	// if(cnt==0) { //*이 0개일때
	//   for(int i=0;i<r;i++){
	//   for(int j=0;j<c;j++){
	//     zzz[i][j]=60;
	//   }
	// }
	// }
	// else bfs(); //시간채우기

	bfs();

	zzz[x][y] = 60;
	bfs2(a, b);



	if (ok == 0) {
		printf("KAKTUS\n");
	}
	else
		printf("%d\n", tot);


	// for(int i=0;i<r;i++){
	//   for(int j=0;j<c;j++){
	//   printf("%d ",zzz[i][j]);
	//   }
	//   printf("\n");
	// }



	return 0;
}