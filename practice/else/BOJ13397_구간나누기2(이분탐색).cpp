/*
	 구간의점수의 최댓값 (: mid) 의 최솟값 (: res)
	 
	 구간의점수의 최댓값을 정하고 그 최댓값보다 크면
	 구간을 나눈다.
*/


#include <iostream>
using namespace std;

int n, m;
int arr[5010];

bool ispossible(int mid) {
	int cnt = 1;
	int maxvalue = arr[0];
	int minvalue = arr[0];
	for (int i = 0; i < n; i++) {
		if (maxvalue < arr[i]) maxvalue = arr[i];
		if (minvalue > arr[i]) minvalue = arr[i];
		if (maxvalue - minvalue > mid) {
			maxvalue = arr[i];
			minvalue = arr[i];
			cnt++;
		}
	}

	if (cnt <= m) return true;
	else return false;
}
int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int s = 0;
	int e = 10000;
	int res = 987654321;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (ispossible(mid)) {
			if (res > mid) res = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}

	cout << res;


	return 0;
}