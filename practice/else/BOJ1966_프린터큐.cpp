#include <iostream>
#include <queue>
using namespace std;

int arr[110];

int main() {
	int tc;
	int m, n;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		queue <pair<int, int>> q;
		priority_queue <int> pq;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			q.push({ arr[i],i });
			pq.push(arr[i]);
		}

		int cnt = 0;
		while (!q.empty()) {

			int curvalue = q.front().first;
			int cur = q.front().second;
			q.pop();

			if (curvalue == pq.top()) {
				pq.pop();
				cnt++;
				if (cur == m) {
					cout << cnt << "\n";
					break;
				}
			}
			else q.push({ curvalue,cur });
		}
	}
	
}