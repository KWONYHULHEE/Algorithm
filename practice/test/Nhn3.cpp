#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[1010][1010];
bool check[1010][1010];
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int cnt = 0;
vector <int> v;
int solve(int x, int y) {
	check[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (check[nx][ny] || arr[nx][ny] == 1)continue;

		solve(nx, ny);

	}

	return cnt;
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == 'W') arr[i][j] = 1;
			else if (temp[j] == 'L') arr[i][j] = 2;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j] && arr[i][j] == 2) {
				cnt = 0;
				v.push_back(solve(i, j));
			}
		}
	}


	sort(v.begin(), v.end());


	int ma = 0;
	for (int i = 0; i < v.size(); i++) {
		if (ma < v[i]) ma = v[i];
	}
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (ma == v[i]) count++;
	}
	for (int i = 0; i < count; i++) {
		v.pop_back();
	}

	if (v.size() == 0) {
		cout << "0" << " " << "0" << " " << "0.00" << " " << "0" << "\n";
		return 0;
	}

	int maxvalue = v[v.size() - 1];
	cout << maxvalue << " ";

	int minvalue = v[0];
	cout << minvalue << " ";

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	double aver = ((double)sum / (double)v.size());
	printf("%0.2f ", aver);

	if (v.size() % 2 == 0) {
		int temp = v.size() / 2;
		int a = v[temp];
		int b = v[temp + 1];
		double mid = ((double)a + (double)b) / 2;
		printf("%0.2f ", mid);
	}
	else {
		int mid = v[v.size() / 2];
		cout << mid << " ";
	}


	return 0;
}