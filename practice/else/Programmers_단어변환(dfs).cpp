#include <string>
#include <vector>

using namespace std;
int answer = 987654321;
bool check[60];
bool ispossible(string cur, string word) {
	int cnt = 0;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] != cur[i]) cnt++;
		if (cnt > 1) return false;
	}
	if (cnt > 1) return false;
	else return true;;
}

void solve(vector<string> words, string cur, string target, int cnt) {

	if (cur == target) {
		if (res > cnt) res = cnt;
		return;
	}

	for (int i = 0; i < words.size(); i++) {
		if (check[i]) continue;
		if (ispossible(cur, words[i])) {
			check[i] = true;
			solve(words, words[i], target, cnt + 1);
			check[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	
	bool flag = false;
	for (int i = 0; i < words.size(); i++) {
		if (target == words[i]) {
			flag = true;
		}
	}
	if (!flag) return 0;

	solve(words, begin, target, 0);

	
	return answer;
}