// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool ispossible(vector<int> v)
{

	bool plus;
	int cur = v[0];
	int next = v[1];
	int len = v.size();

	if (cur - next < 0) plus = true;
	else if (cur - next > 0) plus = false;
	else return false;

	for (int i = 1; i < len - 1; i++) {
		cur = v[i];
		next = v[i + 1];

		if (plus) {
			if (cur - next > 0) plus = false;
			else return false;
		}
		else {
			if (!plus && cur - next < 0) plus = true;
			else return false;
		}
	}

	return true;
}

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	int cnt = 0;
	int answer;
	int len = A.size();
	if (ispossible(A)) return 0;


	for (int i = 0; i < len; i++) {
		vector<int> temp;

		for (int j = 0; j < len; j++) {
			if (i != j) temp.push_back(A[j]);
		}
		if (ispossible(temp)) cnt++;
	}

	if (cnt == 0) answer = -1;
	else answer = cnt;


	return answer;
}