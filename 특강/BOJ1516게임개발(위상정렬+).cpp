#include <iostream>

#include <vector>

#include <queue>

using namespace std;


/*
���� ���

1. A�� ���� ���� B�� ����� �Ѵ�.
2. A�� ���� ���� C�� ����� �Ѵ�.
3. B�� ���� ���� D�� ����� �Ѵ�.

��� �� ���� ������ �ִٰ� ������, A�� ���� �� ����ؾ� �ϴ� �ð���, ���ÿ� ���� �� �����Ƿ�

B + C �� �ƴ�, B�� C �� �� ���� �ɸ��� �ð��� ������ָ� �ȴ�.

*/

const int MAX = 100010;


int N, M;
int inDegree[MAX];
int time[MAX];
int res[MAX];
vector<int> graph[MAX];


void BFS(void)

{

	queue<int> q;
	
	//���� ����

	for (int i = 1; i <= N; i++)

		if (inDegree[i] == 0) {
			q.push(i);
			res[i] = time[i];
		}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();


		for (int i = 0; i < graph[cur].size(); i++)

		{
			int next = graph[cur][i];
			res[next] =  max(res[next], res[cur] + time[next]);  //Point

			inDegree[next]--;

			if (inDegree[next] == 0)
				q.push(next);

		}

	}

}



int main(void)

{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;


	for (int i = 1; i <=N; i++) {
		int a;
		cin >> a;
		time[i] = a;

		while (1) {
			int b;
			cin >> b;
			if (b == -1) break;

			graph[b].push_back(i);   // b�� i���� ���� ����������
			inDegree[i]++; //i�տ� �ϳ� �� ����
		}
	}

	BFS();
	
	for (int i = 1; i <= N; i++) {
		cout << res[i] << "\n";
	}

	return 0;

}