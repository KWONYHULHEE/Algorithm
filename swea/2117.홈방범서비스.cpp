#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int arr[30][30];
int str[30][30];

void distance(int x, int y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			str[i][j] = abs(x - i) + abs(y - j) + 1;
		}
	}
}

int cal() {

	int tot = 0;

	for (int t = 1; t <= n + 1; t++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (str[i][j] <= t && arr[i][j] == 1)
					cnt++;
			}
		}
		if (m*cnt >= t * t + (t - 1)*(t - 1)) {
			if (tot < cnt) tot = cnt;
		}
	}

	return tot;
}
int main() {

	int tc;
	scanf("%d", &tc);


	for (int t = 1; t <= tc; t++) {
		int res = 0;

		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				distance(i, j);
				if (res < cal()) res = cal();
			}
		}

		printf("#%d %d\n", t, res);

		// for(int i=0;i<n;i++){
		//   for(int j=0;j<n;j++){
		//     printf("%d ",str[i][j]);
		//   }
		//   printf("\n");
		// }

	}



	return 0;
}
