#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 201;
long long int D[MAX][MAX];

int main() {

	int n, m, k;
	cin >> n >> m >> k;

	// ÆÄ½ºÄ®ÀÇ »ï°¢Çü(nCr)

	for (int i = 0; i < MAX; i++) {
		D[i][0] = 1;
	}
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j <= i; j++) {
			D[i][j] = min((D[i - 1][j] + D[i - 1][j - 1]), (long long int) 1e9);
		}
	}
	string sb;
	int size = n + m;
	if (k > D[size][n]) {
		cout << "-1" << "\n";
	}
	else {
		for (int i = 0; i < size; i++) {
			if (k > D[n + m - 1][m]) {
				sb.append("z");
				k -= D[n + m - 1][m];
				m--;
			}
			else {
				sb.append("a");
				n--;
			}
		}
	}
	cout << sb << "\n";

	return 0;
}