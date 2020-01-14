#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 10010
using namespace std;

/*

정점 A가 루트 라면 ::
자식 수가 2개 이상이면 단절점이다.


정점 A가 루트가 아니라면 ::
A번 정점에서 자식 노드들이 정점 A를 거치지 않고 정점 A보다 빠른 방문번호를 가진 정점으로 갈 수 없다면 단절점이다.


*/

int n, m, discovered[MAX_N], cut[MAX_N], ans, d, a, b;
vector<vector<int>> vt;

int dfs(int here, bool root) {

	discovered[here] = ++d; // DFS 탐색 순서 지정 (방문번호)
	int ret = discovered[here]; //본인의 방문순서
	int child = 0; //자식수

	for (int i = 0; i < vt[here].size(); i++) {    //모든 정점 탐색하면서 단절점 확인
		int next = vt[here][i];

		if (!discovered[next]) {  //방문 안했으면 
			child++;  //자식 증가
			int temp = dfs(next, false); // 자식노드의 방문번호 

			if (!root&&temp >= discovered[here])  // 자식노드의 방문번호가 정점 here 의 방문번호 보다 느린 방문노드이면 단절점
				cut[here] = true;

			ret = min(ret, temp); // 가장 빠른 방문노드를 찾아야하니까
		}
		else
			ret = min(ret, discovered[next]); //방문 했으면
	}

	if (root&&child > 1)
		cut[here] = true;

	return ret;
}

int main() {

	scanf("%d%d", &n, &m);

	vt.resize(n + 1);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		if (!discovered[i])
			dfs(i, true);   //시작점은 루트노드

	for (int i = 1; i <= n; i++)
		if (cut[i])
			ans++;

	printf("%d\n", ans);

	for (int i = 1; i <= n; i++)
		if (cut[i])
			printf("%d ", i);

	return 0;
}

