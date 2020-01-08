/*

1. maxHeap의 크기가 minHeap의 크기와 같거나, maxHeap이 1 더 크다.
2. maxHeap의 모든 원소는 minHeap의 모든 원소보다 작거나 같다.
즉, maxHeap의 top은 minHeap의 top보다 작거나 같다.


1. maxHeap의 크기는 minHeap과 같거나 1 더 크므로, maxHeap의 사이즈가 더 크면 minHeap에 새로운 원소를 넣어 두 힙의 사이즈를 같게 만들어주고, 
	그게 아니면 현재 두 힙의 사이즈가 동일한 것이므로 maxHeap에 새로운 원소를 넣어준다.
2. 일단 크기만 고려하여 힙에 새로운 원소를 넣었으므로, 
	두 힙에의 top을 비교해서 maxHeap의 top이 minHeap의 top보다 크면 두 원소를 바꿔주면 된다.


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
		// 1. maxHeap의 크기가 minHeap의 크기와 같거나, maxHeap이 1 더 크다.
		if (maxHeap.size() > minHeap.size()) minHeap.push(m);
		else maxHeap.push(m); // 크기동일
		// 2. maxHeap의 top은 minHeap의 top보다 작거나 같다.
		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top()>minHeap.top()) {
			int maxTop = maxHeap.top(), minTop = minHeap.top();
			maxHeap.pop(), minHeap.pop();
			maxHeap.push(minTop);
			minHeap.push(maxTop);
		}
		cout << maxHeap.top() << '\n';
	}
}
