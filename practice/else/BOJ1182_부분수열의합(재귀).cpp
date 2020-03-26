#include <iostream>
using namespace std;

int n, s;
int arr[30];
int cnt = 0;
bool check[30];

void solve(int idx, int sum) {

	sum += arr[idx];

	if (idx >= n) return;

	if (sum == s) cnt++;

	solve(idx + 1, sum - arr[idx]);
	solve(idx + 1, sum);

}

int main() {

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solve(0, 0);
	cout << cnt;
	return 0;
}

