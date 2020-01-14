#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


vector <pair<int, int>> adj[501];
const int INF = 987654321;
int d[501] = { INF };
int n, m;

/*
  ����-���� �˰��� 
  ���� ����ġ

  ��������Ŭ�� �߻��ϸ� -1�� ����϶�� �ϴ�
  n-1���� ���� n��° �ݺ����� ���� ���� ���ŵǴ� �κ��� ������ -1�� ���.

*/

int main()
{

	scanf("%d %d", &n, &m);

	for (int i = 0; i< m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);// ���� ,����, �ð�
		adj[a].push_back({ b,c });
	}


	fill(d, d + 501, INF);

	d[1] = 0;  //��������  = 1;

	bool cycle = false;

	for (int i = 1; i <= n; i++) { //���������� ��� Ȯ��
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < adj[j].size(); k++) {

				int next = adj[j][k].first;
				int next_weight = adj[j][k].second;

				if (d[j] != INF && d[next] > d[j] + next_weight) {
					//d[j] != INF : j��忡�� ������ ������ ����. �ʱ� INF���� �Ⱥ���
					d[next] = d[j] + next_weight;
					if (i == n) {  // n��°�� ���� ���ŵǸ� ��������Ŭ
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
				printf("-1\n"); //��ΰ����ٸ�
			}
			else printf("%d\n", d[i]);
		}
	}

	return 0;
}