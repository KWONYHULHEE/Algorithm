#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool ispossible(vector<int> a, int n, int d, int mid) {

	int cnt = 0;
	int last = 0;
	for (int i = 0; i < a.size(); i++) {
		int gap = (i != a.size() ? a[i] - last : d - last);
		if (gap < mid) {
			cnt++; // 제거하는 바위 갯수
		}
		else {
			last = a[i];
		}
	}

	return cnt > n ? true : false;
}




int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	
	sort(rocks.begin(), rocks.end());

	int start = 1;
	int end = distance;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (!ispossible(mid,rocks,n,distance)) end = mid - 1;
		else {
			start = mid + 1;
			answer = mid;
		}
	}


	return answer;
}