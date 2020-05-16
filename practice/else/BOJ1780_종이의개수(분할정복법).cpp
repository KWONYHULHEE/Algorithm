#include <iostream>
#include <string>
using namespace std;

const int MAX = 2187;

int N;
int arr[MAX][MAX];

int reszero, resminus, resone = 0;

void compress(int n, int x, int y) {


	if (n == 1) {

		if (arr[x][y] == 1) resone++;
		else if (arr[x][y] == 0) reszero++;
		else resminus++;

		return;

	}


	bool zero = true, one = true, minus = true;

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] == 1) {
				zero = false;
				minus = false;
			}
			else if (arr[i][j] == 0) {
				one = false;
				minus = false;
			}
			else {
				one = false;
				zero = false;
			}
		}
	}


	if (zero) reszero++;
	else if (one) resone++;
	else if (minus) resminus++;

	else {

		compress(n / 3, x, y);
		compress(n / 3, x, y + n / 3);
		compress(n / 3, x, y + n / 3 + n / 3);

		compress(n / 3, x + n / 3, y);
		compress(n / 3, x + n / 3, y + n / 3);
		compress(n / 3, x + n / 3, y + n / 3 + n / 3);

		compress(n / 3, x + n / 3 + n / 3, y);
		compress(n / 3, x + n / 3 + n / 3, y + n / 3);
		compress(n / 3, x + n / 3 + n / 3, y + n / 3 + n / 3);

	}

	return;

}



int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}


	compress(N, 0, 0);
	cout << resminus << "\n" << reszero << "\n" << resone << "\n";

	return 0;

}