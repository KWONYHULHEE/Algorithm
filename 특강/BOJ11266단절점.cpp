#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 10010
using namespace std;

/*

���� A�� ��Ʈ ��� ::
�ڽ� ���� 2�� �̻��̸� �������̴�.


���� A�� ��Ʈ�� �ƴ϶�� ::
A�� �������� �ڽ� ������ ���� A�� ��ġ�� �ʰ� ���� A���� ���� �湮��ȣ�� ���� �������� �� �� ���ٸ� �������̴�.


*/

int n, m, discovered[MAX_N], cut[MAX_N], ans, d, a, b;
vector<vector<int>> vt;

int dfs(int here, bool root) {

	discovered[here] = ++d; // DFS Ž�� ���� ���� (�湮��ȣ)
	int ret = discovered[here]; //������ �湮����
	int child = 0; //�ڽļ�

	for (int i = 0; i < vt[here].size(); i++) {    //��� ���� Ž���ϸ鼭 ������ Ȯ��
		int next = vt[here][i];

		if (!discovered[next]) {  //�湮 �������� 
			child++;  //�ڽ� ����
			int temp = dfs(next, false); // �ڽĳ���� �湮��ȣ 

			if (!root&&temp >= discovered[here])  // �ڽĳ���� �湮��ȣ�� ���� here �� �湮��ȣ ���� ���� �湮����̸� ������
				cut[here] = true;

			ret = min(ret, temp); // ���� ���� �湮��带 ã�ƾ��ϴϱ�
		}
		else
			ret = min(ret, discovered[next]); //�湮 ������
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
			dfs(i, true);   //�������� ��Ʈ���

	for (int i = 1; i <= n; i++)
		if (cut[i])
			ans++;

	printf("%d\n", ans);

	for (int i = 1; i <= n; i++)
		if (cut[i])
			printf("%d ", i);

	return 0;
}

