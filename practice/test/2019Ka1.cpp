#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack <int> s;
	for (int i = 0; i < moves.size(); i++) {
		int target = moves[i] - 1;
		for (int j = 0; j < board.size(); j++) {
			if (board[j][target] == 0) continue;
			if (board[j][target] != 0) {

				if (!s.empty() && s.top() == board[j][target]) {
					answer++;
					while (!s.empty()) {
						if (s.top() != board[j][target]) break;
						answer++;
						s.pop();
					}
				}
				else { s.push(board[j][target]); }

				board[j][target] = 0;

				break;

			}
		}
	}
	return answer;
}
