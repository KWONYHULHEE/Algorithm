#include <iostream>
#include <vector>
using namespace std;

int arr[10][10];
vector <pair<int, int>> v;

bool check1(int x, int num) {
	for (int i = 0; i < 9; i++) {
		if (arr[x][i] == num) return false;
	}
	return true;
}

bool check2(int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (arr[i][y] == num) return false;
	}
	return true;
}

bool check3(int x, int y, int num) {

	int s = x / 3;
	int e = y / 3;

	for (int i = s*3; i < (s*3)+3; i++) {
		for (int j = e * 3; j < (e * 3) + 3; j++) {
			if (arr[i][j] == num) return false;
		}
	}
	
	return true;
}
bool ispossible(int x, int y, int i) {
	if (check1(x, i) && check2(y, i) && check3(x, y, i)) return true;
	else return false;
}
void solve(int cnt) {

	if (cnt == v.size()) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			int x = v[cnt].first;
			int y = v[cnt].second;

			if (ispossible(x,y,i)) {
				arr[x][y] = i;
				solve(cnt + 1);
				arr[x][y] = 0;
			}
		}
	}
}
int main()
{
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}

	solve(0);
	

	return 0;
}