
#include <map>
#include <algorithm>
using namespace std;
map <int, int> m;

int solution(vector<int> &A) {

	int len = A.size();
	for (int i = 0; i < len; i++) {
		int temp = A[i];
		m[temp]++;
	}

	bool flag = false;
	int res = -1;

	for (auto it : m) {
		if (it.first == it.second) {
			flag = true;
			res = max(res, it.first);
		}
	}

	if (!flag) return 0;
	else return res;
}