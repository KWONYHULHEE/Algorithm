#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector <pair<int, pair<int, int>>> edge;
int parent[100010];

/*
2. 크루스칼 알고리즘 동작(구현)원리 !
- 크루스칼 알고리즘의 풀이방법을 크게 몇 단계로 나누어서 알아보자.
1. 모든 간선들의 가중치를 오름차순으로 정렬한다.
2. 가중치가 가장 작은 간선을 선택한다.
3. 2에서 선택한 간선이 연결하려는 2개의 노드가 아직 서로 연결되지 않은 상태라면, 2개의 노드를 서로 연결한다.
4. 위의 과정을 반복한다.
*/


int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);  //경로압축
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	parent[a] = b;
}

bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return true;
	else return false;
}


int main()
{

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge.push_back({ c, { a,b } });
	}

	sort(edge.begin(), edge.end());  // 오름차순 정렬
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int res = 0;

	for (int i = 0; i < edge.size(); i++) {
		if (sameparent(edge[i].second.first, edge[i].second.second) == false) { //연결안되있으면
			Union(edge[i].second.first, edge[i].second.second); //합치기
			res += edge[i].first;  //가중치 더해주기
		}
	}


	printf("%d", res);

	return 0;
}
