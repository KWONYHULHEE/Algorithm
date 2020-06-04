#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;

	int k = s / n;
	if (k == 0) {
		answer.push_back(-1);
		return answer;
	}
	int t = s % n;
	for (int i = 0; i < n; i++) answer.push_back(k);
	for (int i = n - 1; i >= n - t; i--) answer[i]++;

	return answer;
}