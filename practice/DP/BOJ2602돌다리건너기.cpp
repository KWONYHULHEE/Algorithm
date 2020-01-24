#include <iostream>
#include <string>
using namespace std;

string look;
string devil;
string angel;
const int MAX = 110;
int dp[MAX][MAX][2];

int solve(int c, int f, int r) {

	if (f == look.size()) return 1;

	if (dp[c][f][r] != -1) return dp[c][f][r];
	
	int total = 0;

	if (r == 0) {
		for (int i = c; i < devil.size(); i++) {
			if (devil[i] == look[f]) total += solve(i + 1, f + 1, 1);
		}
	}
	else {
		for (int i = c; i < angel.size(); i++) {
			if (angel[i] == look[f]) total += solve(i + 1, f + 1, 0);
		}
	}

	return dp[c][f][r]=total;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> look;
	cin >> devil;
	cin >> angel;

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = -1;
			}
		}
	}

	int d = solve(0, 0, 0);
	int a = solve(0, 0, 1);

	cout << a + d << "\n";


	return 0;
}
