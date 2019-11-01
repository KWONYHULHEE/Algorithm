#include<cstdio>

const int MAX = 4000;
struct Atom {
	int x;
	int y;
	int d;
	int energy;
};

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int n, ans;
bool check[MAX + 4][MAX + 4];
int map[MAX + 4][MAX + 4];
Atom atom[MAX + 2];

void go() {

	// int time =1;
	while (1) {
		int tempenergy = 0;

		for (int i = 1; i <= n; i++) {
			if (atom[i].energy == 0) continue;

			int nextx = atom[i].x + dx[atom[i].d];
			int nexty = atom[i].y + dy[atom[i].d];

			if (nextx < 0 || nexty < 0 || nextx >= 4000 || nexty >= 4000) {
				map[atom[i].x][atom[i].y] -= 1;
				atom[i].energy = 0;
			}
			else {
				map[atom[i].x][atom[i].y] -= 1;
				atom[i].x = nextx;
				atom[i].y = nexty;
				map[atom[i].x][atom[i].y] += 1;

				if (map[atom[i].x][atom[i].y] > 1) {
					check[atom[i].x][atom[i].y] = true;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (atom[i].energy == 0) continue;

			if (check[atom[i].x][atom[i].y] == true) {
				if (map[atom[i].x][atom[i].y] == 1)
					check[atom[i].x][atom[i].y] = false;

				map[atom[i].x][atom[i].y] -= 1;
				tempenergy += atom[i].energy;
				atom[i].energy = 0;
			}
		}

		ans += tempenergy;
		// time+=1;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (atom[i].energy == 0)
				cnt++;
		}

		if (cnt == n) return;
	}



}

int main() {

	int tc;

	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d %d", &atom[i].x, &atom[i].y, &atom[i].d, &atom[i].energy);

			atom[i].x += 1000;
			atom[i].y += 1000;
			atom[i].x *= 2;
			atom[i].y *= 2;

			map[atom[i].x][atom[i].y] += 1;

		}

		go();
		printf("#%d %d\n", t, ans);
	}




	return 0;
}