#include <iostream>

#include <vector>

#include <queue>

using namespace std;


/*
예를 들어

1. A를 짓기 위해 B를 지어야 한다.
2. A를 짓기 위해 C를 지어야 한다.
3. B를 짓기 위해 D를 지어야 한다.

라는 세 가지 조건이 있다고 했을때, A를 지을 때 고려해야 하는 시간은, 동시에 지을 수 있으므로

B + C 가 아닌, B와 C 중 더 많이 걸리는 시간만 고려해주면 된다.

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
	
	//위상 정렬

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

			graph[b].push_back(i);   // b가 i보다 먼저 지어져야함
			inDegree[i]++; //i앞에 하나 더 있음
		}
	}

	BFS();
	
	for (int i = 1; i <= N; i++) {
		cout << res[i] << "\n";
	}

	return 0;

}