#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v[30];
set <string>  s;
int answer = 0;
bool check[30];
int result[10];

void solve(int cur, int len) {


	if (cur > len) return;
	if (cur == len) {

		vector <int> tp;
		for (int i = 0; i < len; i++) tp.push_back(result[i]);
		sort(tp.begin(), tp.end());

		string temp;
		for (int i = 0; i < tp.size(); i++) {
			temp += to_string(tp[i]);
		}

		if (s.find(temp) == s.end()) answer++;  //¾øÀ¸¸é 
		s.insert(temp);

		return;
	}

	for (int i = 0; i < v[cur].size(); i++) {
		if (!check[v[cur][i]]) {
			check[v[cur][i]] = true;
			result[cur] = v[cur][i];
			solve(cur + 1, len);
			result[cur] = 0;
			check[v[cur][i]] = false;
		}
	}
}


int solution(vector<string> user_id, vector<string> banned_id) {



	for (int i = 0; i < banned_id.size(); i++) {
		for (int j = 0; j < user_id.size(); j++) {
			bool flag = true;
			if (user_id[j].size() != banned_id[i].size()) {
				flag = false;
				continue;
			}
			for (int k = 0; k < user_id[j].size(); k++) {
				if (banned_id[i][k] == '*') continue;
				if (user_id[j][k] != banned_id[i][k]) {
					flag = false;
					break;
				}
			}
			if (flag) v[i].push_back(j);
		}
	}
	solve(0, banned_id.size());

	return answer;
}