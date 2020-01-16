#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 1010;
int arr[MAX][MAX];
vector <char> ans;
string n, m; 



void getRoute(int r, int c) {
	if (r == 0 || c == 0) return;

	if (n[r-1] == m[c-1]) {
		ans.push_back(n[r-1]);
		getRoute(r - 1, c - 1);
	}
	else {
		if (arr[r - 1][c] > arr[r][c - 1]) getRoute(r - 1, c);
		else getRoute(r, c - 1);
	}
}

int main() {

	

	cin >> n >> m;
	int res = 0;  //****

	for (int i = 1; i <= n.size(); i++) {
		for (int j = 1; j <= m.size(); j++) {
			if (n[i - 1] == m[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				res = max(res, arr[i][j]);
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}


	cout << res << "\n";

	getRoute(n.size(),m.size());

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}



	return 0;

}
