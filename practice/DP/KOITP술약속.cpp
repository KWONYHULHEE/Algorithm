#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
/*
	https://www.koitp.org/problem/USACO_2007JANSILVER_ALCHOL/read/
*/
const int MAX = 100010;

struct PT {
	int t, d;
}promise[MAX];

bool cmp(PT &p, PT &q) {
	return p.t*q.d < p.d*q.t;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> promise[i].t>>promise[i].d;
	}
	
	sort(promise + 1, promise + n + 1, cmp);
	long long sum = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += sum * promise[i].d;
		sum += promise[i].t;
	}

	cout << ans * 2;
	

	return 0;
}

