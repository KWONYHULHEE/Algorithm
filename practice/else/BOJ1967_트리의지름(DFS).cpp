#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> //memset
using namespace std;


const int MAX = 10000 + 1;
int N;
bool visited[MAX]; //�湮 ����
vector<pair<int, int>> graph[MAX]; //�޸𸮸� ���� �� �ִ�

int diameter = 0; //����
int farthestNode = 0; //node ��ȣ�� 1������


void DFS(int node, int cost){

	//���� ���: �̹� �湮�� ���� �ٽ� �湮 ����

	if (visited[node])	return;

	visited[node] = true;


	//���� ������Ʈ

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

	//��Ʈ���� ���� �� ���� ã��

	DFS(1, 0);

	//�ش� �������� ���� �� ���������� �Ÿ��� Ʈ�� ������ ����

	memset(visited, false, sizeof(visited));

	diameter = 0;

	DFS(farthestNode, 0);



	cout << diameter << endl;

	return 0;

}