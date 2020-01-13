#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector <pair<int, pair<int,int>>> edge;
int parent[100010];

/*

2. ũ�罺Į �˰��� ����(����)���� !

- ũ�罺Į �˰����� Ǯ�̹���� ũ�� �� �ܰ�� ����� �˾ƺ���.
1. ��� �������� ����ġ�� ������������ �����Ѵ�.
2. ����ġ�� ���� ���� ������ �����Ѵ�.
3. 2���� ������ ������ �����Ϸ��� 2���� ��尡 ���� ���� ������� ���� ���¶��, 2���� ��带 ���� �����Ѵ�.
4. ���� ������ �ݺ��Ѵ�.

*/

 
int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);  //��ξ���
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

	sort(edge.begin(), edge.end());  // �������� ����
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int res = 0;

	for (int i = 0; i < m; i++) {
		if (sameparent(edge[i].second.first, edge[i].second.second) == false) { //����ȵ�������
			Union(edge[i].second.first, edge[i].second.second); //��ġ��
			res += edge[i].first;  //����ġ �����ֱ�
		}
	}
	

	printf("%d", res);

	return 0;
}