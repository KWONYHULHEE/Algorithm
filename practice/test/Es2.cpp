#include <map>
#include <algorithm>

map<int, vector<int>> m;


int check(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += (x % 10);
		x /= 10;
	}
	return sum;
}

int solution(vector<int> &A) {

	int len = A.size();
	for (int i = 0; i < len; i++) {
		int temp = check(A[i]);
		m[temp].push_back(A[i]);
	}

	int res = -1;
	for (auto it : m) {

		int size = it.second.size();
		if (size >= 2) {
			int fir = -1, sec = -1;
			for (int j = 0; j < size; j++) {
				fir = max(it.second[j], fir);
			}

			for (int j = 0; j < size; j++) {
				if (it.second[j] != fir)
					sec = max(it.second[j], sec);
			}

			res = max(fir + sec, res);

		}
	}

	return res;
}