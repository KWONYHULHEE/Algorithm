#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
1. ���ڸ� �ߺ� �����ϴ� ���� �����ϱ� ���� map�� �̿��մϴ�.

2. �Ҽ��� ���� �켱���� ť�� �Է��ϴµ� �켱���� ť�� ũ�Ⱑ N�� �ʰ��ϰ� �켱���� ť �� �ִ񰪺��� ���� ���ڰ� �� ũ�� �������� �ʽ��ϴ�.

-> �켱���� ť �� �ִ񰪺��� ���� ���ڰ� ������ ���� ���ڰ� �� ���� �����ϹǷ� �켱���� ť�� �ֽ��ϴ�.

3. �ݺ����� Ż���� �� �켱���� ť�� top�� ����մϴ�.*/

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


			if (next > maxvalue && pq.size() > n) //pq �ȿ� �ִ� ���ڵ� �� �ִ񰪺��� ũ�� pq�� ũ�Ⱑ N�� ������ �� �̻� ���ڸ� ���� �ʿ䰡 ����
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