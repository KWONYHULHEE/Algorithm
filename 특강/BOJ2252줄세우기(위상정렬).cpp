#include <iostream>

#include <vector>

#include <queue>

using namespace std;

/*
위상 정렬(Topological Sort) 문제였습니다.



알고리즘은 아래와 같습니다.

1. 각 정점의 inDegree를 파악해줍니다.

2. inDegree가 0이라는 것은 순위가 제일 높을 수 있다는 뜻이므로 큐에 미리 넣어줍니다.

3. 이후로는 큐에 front와 연결되어 있는 정점의 inDegree를 업데이트하고 1번과 2번을 반복해줍니다.

*/


const int MAX = 32000 + 1;



int N, M;

int inDegree[MAX];

vector<int> graph[MAX];


void BFS(void)

{

	queue<int> q;

	//위상 정렬

	for (int i = 1; i <= N; i++)

		if (inDegree[i]==0)
			q.push(i);


	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++)

		{

			inDegree[graph[cur][i]]--;

			if (inDegree[graph[cur][i]]==0)
				q.push(graph[cur][i]);

		}

	}

}



int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	cin >> N >> M;



	for (int i = 0; i < M; i++){
		int a, b;

		cin >> a >> b;
		graph[a].push_back(b);
		inDegree[b]++;
	}



	BFS();

	return 0;

}