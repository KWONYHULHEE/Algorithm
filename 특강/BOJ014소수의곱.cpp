#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
1. 숫자를 중복 삽입하는 것을 방지하기 위해 map을 이용합니다.

2. 소수의 곱을 우선순위 큐에 입력하는데 우선순위 큐의 크기가 N을 초과하고 우선순위 큐 내 최댓값보다 현재 숫자가 더 크면 삽입하지 않습니다.

-> 우선순위 큐 내 최댓값보다 현재 숫자가 작으면 현재 숫자가 더 먼저 등장하므로 우선순위 큐에 넣습니다.

3. 반복문을 탈출한 뒤 우선순위 큐의 top을 출력합니다.*/

const int MAX = 110;
bool check[100010];
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

			if (!check[next]) {
				maxvalue = max(maxvalue, next);
				check[next] = true;
				pq.push(next);
			}
		}
		n--;
	}


	cout << pq.top() << endl;

	return 0;
}