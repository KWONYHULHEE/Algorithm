#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int arr[60][60];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	int num = max(n, m);
	int res = -1;
	for (int k = 1; k <= num; k++) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i + k - 1) >= n || (j + k - 1) >= m) continue;
				int value = arr[i][j];
				if (arr[i][j + k - 1] != value) continue;
				if (arr[i + k - 1][j] != value) continue;
				if (arr[i + k - 1][j + k - 1] != value) continue;

				if (res < k) res = k;
			}
		}
	}
	cout << res*res;
	
	return 0;
}