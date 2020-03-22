#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool check = false;
int visited[10001];
vector<string> answer;

void dfs(vector<vector<string>> tickets, string next, vector<string> str) {
	
	if (str.size() == tickets.size()) {
		str.push_back(next);
		check = true;
		answer = str;
		return;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (check == true) break;
		if (tickets[i][0] == next && !visited[i]) {
			str.push_back(tickets[i][0]);
			visited[i] = 1;
			dfs(tickets, tickets[i][1], str);
			str.pop_back();
			visited[i] = 0;
		}
	}


}
vector<string> solution(vector<vector<string>> tickets) {

	sort(tickets.begin(), tickets.end()); //정렬

	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == "ICN") {
			visited[i] = 1; //ICN 공항부터 방문 시작
			answer.push_back(tickets[i][0]);
			dfs(tickets, tickets[i][1], answer);

			if (check == true) return answer;
			answer.pop_back();
			visited[i] = 0; //모든 정점을 방문하지 못했으면 방문 취소함 (다음 ICN공항 부터 시작)
		}
	}

	return answer;
}