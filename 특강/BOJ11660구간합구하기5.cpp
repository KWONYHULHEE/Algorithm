#include <iostream>
using namespace std;

int n, m;
int arr[1026][1026];
int total[1026][1026];

int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			
		}
	}
	total[1][1] = arr[1][1];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			total[i][j] = total[i - 1][j] + total[i][j - 1] + arr[i][j] - total[i - 1][j - 1];
		}
	}

	for (int k = 0; k < m; k++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int res = total[c][d] - total[a-1][d] - total[c][b-1] + total[a-1][b-1];
		cout << res << "\n";
	}

	return 0;
}