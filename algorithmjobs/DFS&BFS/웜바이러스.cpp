#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 120;
vector <int> arr[MAX];
int n, m;
bool check[MAX];
int cnt = 0;

void dfs(int x) {
	check[x] = true;


	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];

		if (check[y] == false)
			dfs(y);

	}
	cnt++;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(1);
	printf("%d", cnt - 1);

	return 0;
}