#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*
	dp[left][right] : 
	i번째 조각을 기준으로 i-1번째를 왼쪽, i+1번째를 오른쪽이라고 합시다.
	현재 상황까지 가져간 가장 왼쪽 위치는 l, 가장 오른쪽 위치를 r이라고 할 때 
	최댓값을 dp[l][r]로 정의.

*/
int n;
const int MAX = 2010;
long long dp[MAX][MAX];
long long arr[MAX];

long long int PLUS(int x) {
	return (x + 1) % n;
}
long long int MINUS(int x) {
	return (x - 1 + n) % n;
}

long long solve(int left, int right, int turn) {

	if (PLUS(right) == left) return 0;

	long long int& ret = dp[left][right];
	if (ret != -1) return ret;

	if (turn == 0) { //조이
		ret = arr[PLUS(right)] + solve(left, PLUS(right), 1);
		ret = max(ret, arr[MINUS(left)] + solve(MINUS(left), right, 1));
	}
	else {
		if (arr[PLUS(right)] > arr[MINUS(left)]) 
			ret = solve(left, PLUS(right), 0);	
		else 
			ret = solve(MINUS(left),right, 0);	
	}

	return ret;

}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	long long res = -1;

	for (int i = 0; i<n; i++) {
		res = max(res,arr[i]+solve(i,i,1)); //조이가 먹고 시작
	}

	cout << res << "\n";

	return 0;
}