#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
vector <int> arr[10010];
vector <int> tree[10010];
vector <int> result;
int dp[10010][2];
int value[10010];
bool check[10010];

void dfs(int node) {

	check[node] = true;

	for (int i = 0; i < arr[node].size(); i++) {
		int next = arr[node][i];

		if (!check[next]) {
			tree[node].push_back(next);
			dfs(next);
		}

	}

}
int solve(int index, int flag) {

	int& ret = dp[index][flag];
	if (ret != -1) return ret;

	if (flag) 
	{
		ret = value[index];
		for (int i = 0; i < tree[index].size(); i++)
		{

			int next = tree[index][i];
			ret += solve(next, 0);
		}
	}
	else  
	{
		ret = 0; 
		for (int i = 0; i < tree[index].size(); i++)
		{
			int next = tree[index][i];
			ret += max(solve(next, 1), solve(next, 0)); 
		}
	}
	return ret;

}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
	}

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1);
	memset(dp, -1, sizeof(dp));


	cout << max(solve(1, 1), solve(1, 0)) << "\n";





	return 0;
}
