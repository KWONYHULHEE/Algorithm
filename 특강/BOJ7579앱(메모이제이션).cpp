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


//�޸𸮸� �޸������̼�(10,000,000 �ʹ� ũ��)

int maxMemory(int idx, int totalCost){

	//���� ���: ���� �ʰ� ��

	if (idx >= MAX) return 0;

	int &result = cache[idx][totalCost];
	if (result != -1) return result;


	result = maxMemory(idx + 1, totalCost); //�ش� �� ��Ȱ��ȭ �� ������ ���

	//totalCost���� �ش� �ε����� �ִ� ���� ��Ȱ��ȭ ������ ���ų� �۴ٸ�

	//��Ȱ��ȭ �� ���� ���� ��Ȱ��ȭ ���� ���� ���ؼ� �޸𸮰� �� ū �� ����

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

	//0���� �����ؼ� ���ʷ� M ����Ʈ �̻� Ȯ�� �� �� ã��

	while (1){

		if (maxMemory(0, totalCost) >= M){
			cout << totalCost << endl;
			break;
		}
		totalCost++;
	}


	return 0;

}