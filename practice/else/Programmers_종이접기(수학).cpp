#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	vector <int> temp;
	temp.push_back(0);
	int cnt = 1;

	for (int i = 1; i <= n; i++) {
		answer.clear();
		answer.push_back(0);
		bool flag = false;
		int idx = 0;
		for (int j = 0; j < cnt - 1; j++) {
			if ((j % 2) != 0) {
				if (flag) answer.push_back(0);
				else answer.push_back(1);
				flag = !flag;
			}
			else {
				answer.push_back(temp[idx++]);
			}
		}
		temp.clear();
		temp = answer;
		cnt += pow(2, i);
	}


	return answer;
}