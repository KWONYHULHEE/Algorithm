#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool ispossible(int mid, vector<int> stones, int k) {

	vector <int> temp;
	for (int i = 0; i < stones.size(); i++) {
		temp.push_back(stones[i]);
	}
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] - (mid - 1) <= 0) temp[i] = 0;
		else temp[i] -= (mid - 1);
	}
	int cnt = 0;
	for (int i = 0; i < temp.size(); i++) {
		if (cnt >= k) return false;
		if (temp[i] == 0) cnt++;
		else if (temp[i] != 0) cnt = 0;
	}
	if (cnt >= k) return false;
	return true;
}
int solution(vector<int> stones, int k) {
	long long answer = 0;

	long long start = 0;
	long long end = 200000000;

	long long res = 0;
	while (start <= end) {
		long long mid = (start + end) / 2;
		if (ispossible(mid, stones, k)) {
			if (answer < mid) answer = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}


	return answer;
}