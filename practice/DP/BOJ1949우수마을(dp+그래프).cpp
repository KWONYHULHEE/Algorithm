#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
vector <int> arr[10010];
int dp[10010][2];
int people[10010];
bool check[10010];

int solve(int index, int flag) {

	int& ret = dp[index][flag];
	if (ret != -1) return ret;

	ret = 0;
	check[index] = true;


	for (int i = 0; i < arr[index].size(); i++) {
		int next = arr[index][i];
		if (!check[next]) {
			if (flag == 1) { //우수마을이면
				ret += solve(next, 0);
			}

			else { //우수마을이 아니면
				ret += max(solve(next, 1) + people[next], solve(next, 0));
			}

		}
	}

	check[index] = false;
	return ret;

}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
	}

	for (int i = 1; i <n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	memset(dp, -1, sizeof(dp));
	memset(check, false, sizeof(check));

	cout << max(solve(1, 1)+people[1], solve(1, 0));
	return 0;
}