#include <stdio.h>
#include <vector>
using namespace std;
vector <int> arr[1010];
int n, x, y;
bool check[1010];
int res;


void dfs(int x, int y, int dep) {

	if (x == y) {
		// printf("%d\n",dep);
		res = dep;
		return;
	}

	else {
		for (int i = 0; i < arr[x].size(); i++) {
			int k = arr[x][i];
			if (check[k] == false) {
				check[k] = true;
				dfs(k, y, dep + 1);
			}
		}
	}
}
int main() {

	//Please Enter Your Code Here

	scanf("%d %d %d", &n, &x, &y);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(x, y, 0);
	printf("%d", res);
	return 0;
}