#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
const int MAX = 100000;

void solve(int x) {
	bool check[100001] = { 0, };
	queue <pair<int, int>> q;
	check[x] = true;
	q.push({ x,0 });

	while (!q.empty()) {

		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == k) {
			cout << cnt << "\n";
			return;
		}

		if (cur + 1 <= MAX && !check[cur + 1]) {
			check[cur + 1] = true;
			q.push({ cur + 1,cnt + 1 });
		}

		if (cur - 1 >= 0 && !check[cur - 1]) {
			check[cur - 1] = true;
			q.push({ cur - 1,cnt + 1 });
		}

		if (cur * 2 <= MAX && !check[cur * 2]) {
			check[cur * 2] = true;
			q.push({ cur * 2 ,cnt + 1 });
		}

	}

}

int main() {



	cin >> n >> k;

	solve(n);

	return 0;
}