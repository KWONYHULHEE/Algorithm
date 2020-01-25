#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100010;
int arr[MAX];
int dp[5][5][MAX];

int force(int a, int b) {
	
	if (a == 0) return 2;
	if (abs(a - b) == 2) return 4;
	if (a == b) return 1;
	return 3;
}

int solve(int left, int right, int cur) { //cur=현재index pre,next=왼발 오른발

	if (arr[cur] == 0) return 0;
	
	int& ret = dp[left][right][cur];
	if (ret != -1) return ret;


	ret = force(left, arr[cur]) + solve(arr[cur], right, cur + 1);  //왼발로 움직였을때 
	ret = min(ret, force(right, arr[cur]) + solve(left, arr[cur], cur + 1)); //오른발로 

	return ret;

}
int main() {


	int index = 0;

	while (1) {
		int a;
		cin >> a;
		arr[index++] = a;
		if (a == 0) break;
	}

	memset(dp, -1, sizeof(dp));

	cout<<solve(0,0,0)<<"\n";



	return 0;
}
