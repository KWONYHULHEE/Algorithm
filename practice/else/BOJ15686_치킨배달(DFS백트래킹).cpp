#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[50][50];
bool check[50];

vector <pair<int, int>> house;
vector <pair<int, int>> chicken;
int res = 987654321;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int distance(pair<int, int> a, pair<int, int> b) {

	return abs(a.first - b.first) + abs(a.second - b.second);

}

void dfs(int target, int cnt) {

	if (cnt == m) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int temp = 987654321;
			for (int j = 0; j < chicken.size(); j++) {
				if (check[j]) {
					int dis = distance(chicken[j], house[i]);
					if (temp > dis) temp = dis;
				}
			}
			sum += temp;
		}
		if (res > sum) res = sum;
		return;
	}


	for (int i = target; i < chicken.size(); i++) {
		if (check[i]) continue;

		check[i] = true;
		dfs(i, cnt + 1);
		check[i] = false;
	}


}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) chicken.push_back({ i,j });
			if (arr[i][j] == 1) house.push_back({ i,j });
		}
	}

	dfs(0, 0);
	cout << res;
	return 0;
}