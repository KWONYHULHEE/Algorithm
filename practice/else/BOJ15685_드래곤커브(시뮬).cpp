#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[110][110];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
vector <int> v;
int a, b;
int res = 0;
void dragon_curve() {

	for (int i = v.size() - 1; i >= 0; i--)
	{
		int temp = (v[i] + 1) % 4;
		a = a + dx[temp];
		b = b + dy[temp];
		arr[a][b] = 1;

		v.push_back(temp);

	}
	
}

void square_count() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j]&& arr[i + 1][j]&& arr[i][j - 1]&& arr[i + 1][j - 1])
				res++;
		}
	}
}
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		v.clear();
		arr[x][y] = 1;
		a = x + dx[d];
		b = y + dy[d];
		arr[a][b] = 1;
		v.push_back(d);

		for (int i = 0; i < g; i++) {
			dragon_curve();
		}
		
	}
	square_count();
	cout << res;
	return 0;
}