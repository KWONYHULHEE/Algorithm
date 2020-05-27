#include <iostream>
#include <algorithm>
#include <cstring> //memset
using namespace std;



const int INF = 987654321;
const int MAX = 1000;


int N;
int arr[MAX];
int cache[MAX];


int minJump(int start){

	if (start == N - 1) return 0; //목적지 도달할 경우
	if (start >= N) return INF; //목적지 도달 못할 경우


	int &result = cache[start];
	if (result != -1) return result;

	result = INF;

	for (int i = 1; i <= arr[start]; i++) //arr[start]이하 갈 수 있으므로
		result = min(result, 1 + minJump(start + i));

	return result;

}



int main(void){

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];



	memset(cache, -1, sizeof(cache));

	int result = minJump(0);

	if (result == INF)	cout << -1 << endl;
	else cout << result << endl;

	return 0;

}
