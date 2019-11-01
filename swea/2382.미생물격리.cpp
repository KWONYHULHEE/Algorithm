#include <cstdio>


const int MAX = 1010;

int arr[110][110];
int N, M, K;
struct Group {
	int x, y, n, d;
};
Group group[MAX];

void init() {
	for (int i = 0; i < 110; i++) {
		for (int j = 0; j < 110; j++) {
			arr[i][j] = 0;
		}
	}
}
void solve() {

	for (int t = 1; t <= M; t++) {
		for (int i = 0; i < K; i++) {
			if (group[i].d == 0) continue;

			arr[group[i].x][group[i].y] -= 1;

			if (group[i].d == 1) group[i].x--;
			else if (group[i].d == 2) group[i].x++;
			else if (group[i].d == 3) group[i].y--;
			else if (group[i].d == 4) group[i].y++;

			arr[group[i].x][group[i].y] += 1;
		}
		for (int i = 0; i < K; i++) {
			if (group[i].d == 0) continue;

			if (group[i].x == 0 || group[i].y == 0 || group[i].x == N - 1 || group[i].y == N - 1) {
				group[i].n /= 2;
				if (group[i].n == 0) {
					group[i].d = 0;
					continue;
				}
				if (group[i].d % 2 == 0) group[i].d -= 1;
				else group[i].d += 1;
			}
		}

		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {

				if (arr[a][b] >= 2) {
					int sum = 0;
					int max_n = 0;
					int max_d = 0;
					int value = 0;
					for (int i = 0; i < K; i++) {
						if (group[i].d == 0) continue;
						if (group[i].x == a && group[i].y == b) {
							if (max_n < group[i].n) {
								max_n = group[i].n;
								max_d = group[i].d;
								value = i;
							}
							sum += group[i].n;
							arr[a][b] -= 1;
							group[i].n = 0;
							group[i].d = 0;
						}
					}
					group[value].n = sum;
					group[value].d = max_d;
					arr[a][b] += 1;

				}
			}
		}

	}




}
int main() {

	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++)
	{
		init();

		scanf("%d %d %d", &N, &M, &K);

		for (int i = 0; i < K; i++) {
			scanf("%d %d %d %d", &group[i].x, &group[i].y, &group[i].n, &group[i].d);

			arr[group[i].x][group[i].y] += 1;
		}

		solve();
		int tot = 0;
		for (int i = 0; i < K; i++) {
			if (group[i].d == 0) continue;

			tot += group[i].n;

		}

		printf("#%d %d\n", t, tot);
	}


	return 0;
}