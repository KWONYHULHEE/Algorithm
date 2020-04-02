#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10];
bool check[10];
int res[10];
int ans = 0;

int ispossible() {
	int sum = 0;

	for (int i = 0; i < n - 1; i++) {
		sum += abs(res[i] - res[i + 1]);
	}
	return sum;
}
void solve(int x) {

	if (x==n) {
		int temp = ispossible();
		if (temp > ans) ans = temp;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			res[x] = arr[i];
			solve(x + 1);
			check[i] = false;
			res[x] = 0;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solve(0);
	cout << ans;
	
	return 0;
}