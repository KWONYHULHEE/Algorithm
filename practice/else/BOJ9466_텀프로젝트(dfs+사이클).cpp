#include <iostream>
#include <cstring> //memset
using namespace std;

const int MAX = 100000 + 1;


int N, cnt;
int want[MAX];
bool visited[MAX];
bool done[MAX]; //방문이 끝났는지 여부


void DFS(int nodeNum){

	visited[nodeNum] = true;

	int next = want[nodeNum];

	if (!visited[next]) DFS(next); 

	//이미 방문했지만 방문이 끝난 노드가 아니라면 사이클
	else if (!done[next]){

		//팀원을 모두 센다

		for (int i = next; i != nodeNum; i = want[i]) cnt++;

		cnt++; //자기 자신을 센다.
	}

	done[nodeNum] = true; //더 이상 해당 노드를 방문할 일이 없다
}



int main(void)

{

	int T;
	cin >> T;



	for (int i = 0; i < T; i++) {

		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));

		cin >> N;

		for (int j = 1; j <= N; j++)	cin >> want[j];

		cnt = 0;

		for (int j = 1; j <= N; j++) {
			if (!visited[j]) {
				DFS(j); //팀을 이루는 사람들을 센다
			}
		}

		cout << N - cnt << endl;

	}

	return 0;

}