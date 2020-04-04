#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
	// 1. ���� ����
	vector<char> st;

	// 2. ���ڸ��� ���� ū ���� �ǰԲ� ���ÿ� ������ ����
	for (auto elem : number) {
		while (!st.empty() && st.back() < elem && k > 0) {
			st.pop_back();
			k -= 1;
		}
		st.push_back(elem);
	}

	// 3. k�� ���Ҵٸ�, ���� �ڿ��� k�� ����
	while (k > 0) {
		st.pop_back();
		k -= 1;
	}

	string answer = "";

	for (auto elem : st) {
		answer += elem;
	}

	return answer;
}