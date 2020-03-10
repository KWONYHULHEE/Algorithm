#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX = 110;
map<long long, bool> visited;
long long arr[MAX];


int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k, n;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	cin >> k >> n;

	for (int i = 0; i < k; i++) cin >> arr[i];

	pq.push(1);

	long long maxvalue = 0;


	while (n) {

		long long cur = pq.top();
		pq.pop();

		for (int i = 0; i < k; i++) {
			long long next = arr[i] * cur;


			if (next > maxvalue && pq.size() > n) //pq 안에 있는 숫자들 중 최댓값보다 크고 pq의 크기가 N을 넘으면 더 이상 숫자를 넣을 필요가 없다
				continue;

			if (!visited[next]) {  //key(키값)에 해당하는 원소들(value들)의 개수를 반환
				maxvalue = max(maxvalue, next);
				visited[next] = true;
				pq.push(next);
			}
		}
		n--;
	}


	cout << pq.top() << endl;

	return 0;
}
