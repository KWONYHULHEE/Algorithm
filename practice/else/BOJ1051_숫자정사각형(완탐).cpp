#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int n, m;
int arr[60][60];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}

	int cnt = 1;

	for (int k = 1; k <= min(n, m); k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int temp = arr[i][j];
				if (i + k >= n || j + k >= m) continue;
				if (arr[i][j + k] != temp) continue;
				if (arr[i + k][j] != temp) continue;
				if (arr[i + k][j + k] != temp) continue;

				if (cnt < k + 1) cnt = k + 1;
					
			}
		}
	}
	cout << cnt * cnt;

	return 0;

}

