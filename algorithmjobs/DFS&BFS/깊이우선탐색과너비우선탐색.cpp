#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
const int MAX = 1000010;
vector <int> arr[MAX];
bool check[MAX];

void bfs() {
	bool check[MAX] = { 0, };
	queue <int> q;
	q.push(0);
	check[0] = true;

	while (!q.empty()) {
		int current = q.front();
		printf("%d ", q.front());
		q.pop();

		for (int i = 0; i < arr[current].size(); i++) {
			int next = arr[current][i];

			if (check[next] == false)
			{
				check[next] = true;
				q.push(next);
			}

		}
	}
}

void dfs(int x) {
	check[x] = true;
	printf("%d ", x);
	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];

		if (check[y] == false)
			dfs(y);
	}
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		sort(arr[i].begin(), arr[i].end());
	}

	dfs(0);
	printf("\n");
	bfs();


	return 0;
}