#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m;
const int MAX = 1000010;
vector <int> arr[MAX];
int s, e;
int cnt = 0;


void bfs(int x) {
	bool check[MAX] = { 0, };
	queue <int> q;
	check[x] = true;
	q.push(x);

	while (!q.empty()) {
		int size = q.size();
		cnt++;
		while (size--) {

			int current = q.front();
			q.pop();


			for (int i = 0; i < arr[current].size(); i++) {
				int next = arr[current][i];

				if (check[next] == false) {
					check[next] = true;
					q.push(next);
				}

				if (next == e)
					return;
			}
		}
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
	scanf("%d %d", &s, &e);

	bfs(s);
	printf("%d", cnt);


	return 0;
}