#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n,m,k;
string arr[1010];
vector <pair<int,string>> graph[510];
int dp[1010][1010];
bool check[1010];

int solve(int cur, int num) {

	if (num == n) return 0;

	int& ret = dp[cur][num];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i].first;
		string nextcolor = graph[cur][i].second;

		
		if (nextcolor == arr[num]) {

			ret = max(ret, solve(next,num+1) + 10);
		}
		else {

			ret = max(ret, solve(next, num+1));
		}
	
	}

	return ret;


}
int main() {


	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	cin >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b; string c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	memset(dp, -1, sizeof(dp));

	cout<<solve(1,0);



	return 0;
}