#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct Strahler {
	int max, order_cnt[1001], order;
};

int indegree[1001];
int k, kk, m, p, a, b;

int main() {

	scanf("%d", &k);

	while (k--) {

		scanf("%d %d %d", &kk, &m, &p);
		memset(indegree, 0, sizeof(indegree));

		vector<vector<int>> vec(m + 1);
		for (int i = 0; i < p; ++i) {
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
			indegree[b]++;
		}

		vector<Strahler> st(m + 1);
		queue<int> q;


		for (int i = 1; i <= m; ++i) {
			if (!indegree[i]) {
				q.push(i);
				st[i].order = 1;
			}
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < vec[cur].size();i++) {
				int next = vec[cur][i];
				if (st[next].max < st[cur].order)  //next의 최대 순서보다 들어오는강(cur)순서가 더크면 
					st[next].max = st[cur].order;

				st[next].order_cnt[st[cur].order]++; //next의 들어오는강(cur)의 순서값의 개수 증가

				indegree[next]--;   
				if (!indegree[next]) {    //내차례
					if (st[next].order_cnt[st[next].max] == 1)  //들어오는 모든 강 중에서 Strahler 순서가 i인 강이 1개이면 순서는 i
						st[next].order = st[next].max;
					else if (st[next].order_cnt[st[next].max] > 1) //2개 이상이면 순서는 i+1이다.
						st[next].order = st[next].max + 1;
					q.push(next);
				}
			}
		}
		printf("%d %d\n", kk, st[m].order);
	}
	return 0;
}
