#include <vector>
#include <map>
using namespace std;

map<char, int> tree;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	
	for (int i = 0; i < skill.length(); i++)
		tree[skill[i]] = i + 1;

	for (auto skt : skill_trees) {
		int count = 1;
		bool check = true;
		for (int i = 0; i < skt.length(); i++) {
			if (tree[skt[i]] > count) {
				check = false;
				break;
			}
			else if (tree[skt[i]] == count)
				count++;
		}
		if (check)
			answer++;
	}
	return answer;
}