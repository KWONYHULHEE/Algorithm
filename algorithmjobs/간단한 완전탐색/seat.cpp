#include <stdio.h>
int arr[1010][1010];
int c, r, n;
int cnt = 1;

int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &c, &r);
	scanf("%d", &n);
	for (int i = 0; i <= c + 1; i++) {
		for (int j = 0; j <= r + 1; j++) {
			arr[i][j] = -1;
		}
	}
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= r; j++) {
			arr[i][j] = 0;
		}
	}
	int x = 1;
	int y = 0;

	while (cnt < c*r) {


		while (1) {
			if (arr[x][y] == n) {
				printf("%d %d", x, y);
				return 0;
			}
			y++;
			if (arr[x][y] != 0) {
				y--;
				break;
			}

			arr[x][y] = cnt;
			cnt++;
		}
		while (1) {
			if (arr[x][y] == n) {
				printf("%d %d", x, y);
				return 0;
			}


			x++;
			if (arr[x][y] != 0) {
				x--;
				break;
			}

			arr[x][y] = cnt;
			cnt++;

		}
		while (1) {
			if (arr[x][y] == n) {
				printf("%d %d", x, y);
				return 0;
			}

			y--;
			if (arr[x][y] != 0) {
				y++;
				break;
			}

			arr[x][y] = cnt;
			cnt++;
		}
		while (1) {
			if (arr[x][y] == n) {
				printf("%d %d", x, y);
				return 0;
			}


			x--;
			if (arr[x][y] != 0) {
				x++;
				break;
			}

			arr[x][y] = cnt;
			cnt++;
		}
	}

	printf("0");

	// for(int i=1;i<=c;i++){
	//     for(int j=1;j<=r;j++){
	//       printf("%d ",arr[i][j]);
	//     }
	//     printf("\n");
	//   }

	return 0;
}