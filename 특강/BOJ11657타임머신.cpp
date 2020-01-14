#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


vector <pair<int, int>> adj[501];
const int INF = 987654321;
int d[501] = { INF };
int n, m;

/*
  벨만-포드 알고리즘 
  음수 가중치

  음수싸이클이 발생하면 -1을 출력하라고 하니
  n-1까지 돌고 n번째 반복문을 돌때 값이 갱신되는 부분이 있으면 -1을 출력.

*/

int main()
{

	scanf("%d %d", &n, &m);

	for (int i = 0; i< m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);// 시작 ,도착, 시간
		adj[a].push_back({ b,c });
	}


	fill(d, d + 501, INF);

	d[1] = 0;  //시작정점  = 1;

	bool cycle = false;

	for (int i = 1; i <= n; i++) { //음수있으니 계속 확인
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < adj[j].size(); k++) {

				int next = adj[j][k].first;
				int next_weight = adj[j][k].second;

				if (d[j] != INF && d[next] > d[j] + next_weight) {
					//d[j] != INF : j노드에서 나가는 간선이 없음. 초기 INF값이 안변함
					d[next] = d[j] + next_weight;
					if (i == n) {  // n번째에 값이 갱신되면 음수싸이클
						cycle = true;
					}
				}
			}
		}
	}


	if (cycle) printf("-1\n");

	else {
		for (int i = 2; i <= n; i++) {
			if (d[i] == INF) {
				printf("-1\n"); //경로가없다면
			}
			else printf("%d\n", d[i]);
		}
	}

	return 0;
}