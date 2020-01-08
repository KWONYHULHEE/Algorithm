/*

1. maxHeap�� ũ�Ⱑ minHeap�� ũ��� ���ų�, maxHeap�� 1 �� ũ��.
2. maxHeap�� ��� ���Ҵ� minHeap�� ��� ���Һ��� �۰ų� ����.
��, maxHeap�� top�� minHeap�� top���� �۰ų� ����.


1. maxHeap�� ũ��� minHeap�� ���ų� 1 �� ũ�Ƿ�, maxHeap�� ����� �� ũ�� minHeap�� ���ο� ���Ҹ� �־� �� ���� ����� ���� ������ְ�, 
	�װ� �ƴϸ� ���� �� ���� ����� ������ ���̹Ƿ� maxHeap�� ���ο� ���Ҹ� �־��ش�.
2. �ϴ� ũ�⸸ ����Ͽ� ���� ���ο� ���Ҹ� �־����Ƿ�, 
	�� ������ top�� ���ؼ� maxHeap�� top�� minHeap�� top���� ũ�� �� ���Ҹ� �ٲ��ָ� �ȴ�.


*/


#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		// 1. maxHeap�� ũ�Ⱑ minHeap�� ũ��� ���ų�, maxHeap�� 1 �� ũ��.
		if (maxHeap.size() > minHeap.size()) minHeap.push(m);
		else maxHeap.push(m); // ũ�⵿��
		// 2. maxHeap�� top�� minHeap�� top���� �۰ų� ����.
		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top()>minHeap.top()) {
			int maxTop = maxHeap.top(), minTop = minHeap.top();
			maxHeap.pop(), minHeap.pop();
			maxHeap.push(minTop);
			minHeap.push(maxTop);
		}
		cout << maxHeap.top() << '\n';
	}
}
