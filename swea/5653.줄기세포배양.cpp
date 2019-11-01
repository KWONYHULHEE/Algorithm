#include <cstdio>
#include <queue>
using namespace std;

int t, m, n, k;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

const int MAX = 350;
struct Cell {
	int state;
	int life;
	int unactivetime;
	int activetime;
};

struct Point {
	int x;
	int y;
};

Cell box[MAX][MAX];

int main() {

	scanf("%d", &t);

	for (int textcase = 1; textcase <= t; textcase++) {
		Cell initcell;
		initcell.state = -1;
		initcell.life = 0;
		initcell.unactivetime = 0;
		initcell.activetime = 0;

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				box[i][j] = initcell;
			}
		}

		scanf("%d %d %d", &n, &m, &k);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int life;
				scanf("%d", &life);

				if (life > 0) {
					Cell cell;
					cell.state = 0;
					cell.life = life;
					cell.activetime = life;
					cell.unactivetime = life;

					box[i + 150][j + 150] = cell;
				}
			}
		}

		int time = 0;
		while (time < k) {
			queue <Point> activecells;
			for (int i = 0; i < MAX; i++) {
				for (int j = 0; j < MAX; j++) {
					if (box[i][j].state == 0) {
						if (box[i][j].unactivetime > 0) {
							box[i][j].unactivetime--;
						}
						if (box[i][j].unactivetime == 0) {
							box[i][j].state = 1;
						}
					}
					else if (box[i][j].state == 1) {
						if (box[i][j].activetime > 0) {
							activecells.push({ i,j });
							box[i][j].activetime--;
						}
						if (box[i][j].activetime == 0) {
							box[i][j].state = 2;
						}
					}
				}
			}

			while (!activecells.empty()) {

				Point current = activecells.front();
				activecells.pop();

				for (int i = 0; i < 4; i++) {
					int x = current.x + dx[i];
					int y = current.y + dy[i];

					if (x < 0 || y < 0 || x >= MAX || y >= MAX) continue;

					if (box[x][y].state < 0) {
						box[x][y].state = 0;
						box[x][y].life = box[current.x][current.y].life;
						box[x][y].unactivetime = box[current.x][current.y].life;
						box[x][y].activetime = box[current.x][current.y].life;

					}
					else if (box[x][y].state == 0 && box[x][y].life == box[x][y].unactivetime) {
						if (box[x][y].life < box[current.x][current.y].life) {
							box[x][y].life = box[current.x][current.y].life;
							box[x][y].unactivetime = box[current.x][current.y].life;
							box[x][y].activetime = box[current.x][current.y].life;
						}
					}
				}
			}
			time++;
		}


		int total = 0;

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (box[i][j].state == 0 || box[i][j].state == 1)
					total++;
			}
		}

		printf("#%d %d\n", textcase, total);
	}

	return 0;
}