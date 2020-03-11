#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int n;
priority_queue <int, vector<int>, greater<int>> pq;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	if (n == 1) {
		cout << "0" << "\n";
		return 0;
	}

	int sum = 0;
	while (!pq.empty()) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		sum += (a + b);
		if (pq.empty()) break;
		pq.push(a+b);
	}

	cout << sum << "\n";


	return 0;

}