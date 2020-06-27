#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> //memset
using namespace std;


const int MAX = 10000 + 1;
int N;
bool visited[MAX]; //방문 여부
vector<pair<int, int>> graph[MAX]; //메모리를 줄일 수 있다

int diameter = 0; //지름
int farthestNode = 0; //node 번호는 1번부터


void DFS(int node, int cost){

	//기저 사례: 이미 방문한 곳은 다시 방문 못함

	if (visited[node])	return;

	visited[node] = true;


	//지름 업데이트

	if (diameter < cost){

		diameter = cost;
		farthestNode = node;

	}


	for (int i = 0; i < graph[node].size(); i++)
		DFS(graph[node][i].first, cost + graph[node][i].second);

}



int main(void){

	cin >> N;

	for (int i = 1; i < N; i++){

		int node1, node2, cost;
		cin >> node1 >> node2 >> cost;


		graph[node1].push_back(make_pair(node2, cost));
		graph[node2].push_back(make_pair(node1, cost));

	}

	memset(visited, false, sizeof(visited));

	//루트에서 가장 먼 정점 찾고

	DFS(1, 0);

	//해당 정점에서 가장 먼 정점까지의 거리가 트리 지름의 정해

	memset(visited, false, sizeof(visited));

	diameter = 0;

	DFS(farthestNode, 0);



	cout << diameter << endl;

	return 0;

}