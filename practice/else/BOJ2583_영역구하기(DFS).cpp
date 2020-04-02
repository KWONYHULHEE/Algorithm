#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,k;
int arr[110][110];
bool check[110][110];
vector <int>v;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int res = 0;
void solve(int x, int y) {

	check[x][y] = true;
	res++;

	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];
		if (a < 0 || b < 0 || a >= n || b >= m ||check[a][b]||arr[a][b]==1) continue;

		solve(a, b);
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		for (int i = b; i <= d-1; i++) {
			for (int j = a; j <= c-1; j++) {
				arr[i][j] = 1;
			}
		}
	}

	int group = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] ==0 && !check[i][j]) {
				group++;
				solve(i,j);
				v.push_back(res);
				res = 0;
			}
		}
	}

	cout << group << "\n";
	sort(v.begin(), v.end());

	for (auto i : v)
		cout << i << " ";
	
	return 0;
}