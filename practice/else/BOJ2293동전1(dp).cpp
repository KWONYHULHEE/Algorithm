#include <iostream>
using namespace std;

int N, K;
int V[101];
int cache[10001];

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> V[i];


	cache[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if (0 <= j - V[i]) cache[j] += cache[j - V[i]];
		}
	}

	//! 정답을 출력한다.
	cout << cache[K];
}