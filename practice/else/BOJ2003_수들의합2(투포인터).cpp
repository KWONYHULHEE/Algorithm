#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int arr[10010];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	int cnt = 0;
	int l = 0;
	int r = 0;

	while (1) {

		if (sum >= m) sum -= arr[l++];
		else if (r == n) break;
		else sum += arr[r++];

		if (sum == m) cnt++;

	}

	cout << cnt;

	return 0;

}

