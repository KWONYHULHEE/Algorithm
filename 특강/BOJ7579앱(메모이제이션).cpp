#include <iostream>
#include <algorithm>
#include <cstring> //memset
using namespace std;



const int MAX = 100;
const int MAXCOST = 10000 + 1;


int N, M;
int memory[MAX];
int cost[MAX];
int cache[MAX][MAXCOST];


//메모리를 메모이제이션(10,000,000 너무 크다)

int maxMemory(int idx, int totalCost){

	//기저 사례: 범위 초과 시

	if (idx >= MAX) return 0;

	int &result = cache[idx][totalCost];
	if (result != -1) return result;


	result = maxMemory(idx + 1, totalCost); //해당 앱 비활성화 안 시켰을 경우

	//totalCost보다 해당 인덱스에 있는 앱의 비활성화 가격이 같거나 작다면

	//비활성화 안 했을 때와 비활성화 했을 때와 비교해서 메모리가 더 큰 쪽 선택

	if (cost[idx] <= totalCost)
		result = max(result, memory[idx] + maxMemory(idx + 1, totalCost - cost[idx]));


	return result;

}



int main(void)

{

	cin >> N >> M;

	for (int i = 0; i < N; i++)

		cin >> memory[i];

	for (int i = 0; i < N; i++)

		cin >> cost[i];

	memset(cache, -1, sizeof(cache));

	int totalCost = 0;

	//0부터 시작해서 최초로 M 바이트 이상 확보 시 답 찾음

	while (1){

		if (maxMemory(0, totalCost) >= M){
			cout << totalCost << endl;
			break;
		}
		totalCost++;
	}


	return 0;

}