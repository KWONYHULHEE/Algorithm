#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000001;
int n;
int dp[MAX][2];
vector <int> v[MAX];
vector <int> tree[MAX];
bool check[MAX];

void dfs(int node) {
	
	check[node] = true;

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];

		if (!check[next]) {
			tree[node].push_back(next);
			dfs(next);
		}
			
	}

}
int solve(int node, int flag) {
	
	int& ret = dp[node][flag];
	if (ret != -1) return ret;

	

	if (flag == 0) { //내가 얼리가 아니면
		ret = 0;
		for (int i = 0; i < tree[node].size(); i++) {
			int next = tree[node][i];
			ret += solve(next, 1); //얼리
			
		}
	}
	else {
		ret = 1;
		for (int i = 0; i < tree[node].size(); i++) {
				int next = tree[node][i];		
				ret += min(solve(next, 0), solve(next, 1));
			
		}
	}


	return ret;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(dp, -1, sizeof(dp));

	dfs(1);
	cout << min(solve(1, 1), solve(1, 0));



	return 0;
}