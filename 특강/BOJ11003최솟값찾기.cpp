#include <stdio.h>
#include <deque>
#include <algorithm>
using namespace std;

int n, l, a;
deque<pair<int, int>> dq;

int main() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; ++i) {
		while (dq.size() && dq.front().second <= i - l)
			dq.pop_front();

		scanf("%d", &a);
		while (dq.size() && dq.back().first >= a)
			dq.pop_back();

		dq.push_back({ a,i });
		printf("%d ", dq.front().first);
	}
	return 0;
}
