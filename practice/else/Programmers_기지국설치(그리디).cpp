#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	int start = 1;
	bool done = false;

	for (int i = 0; i < stations.size(); i++) {
		int l = stations[i] - w - 1;
		int len = l - start + 1;
		if (len < 0) len = 0;
		answer += len / (w * 2 + 1);
		answer += (len % (w * 2 + 1) == 0) ? 0 : 1;
		int r = stations[i] + w + 1;
		if (r > n) {
			done = true;
			break;
		}
		start = r;
	}
	//맨마지막 n번째 남았을때 
	if (!done) {
		int len = n - start + 1;
		answer += len / (w * 2 + 1);
		answer += (len % (w * 2 + 1) == 0) ? 0 : 1;
	}
	return answer;
}

