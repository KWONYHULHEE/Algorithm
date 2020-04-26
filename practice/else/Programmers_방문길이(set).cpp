#include <string>
#include <iostream>
#include <set>
using namespace std;

set <pair<pair<int,int>,pair<int, int>>> s;

int solution(string dirs) {
	int answer = 0;
	int a = 0;
	int b = 0;

	for (int i = 0; i < dirs.size(); i++) {

		if (dirs[i] == 'U') {
			b++;
			if (a < -5 || a>5 || b < -5 || b>5) {
				b--;
				continue;
			}
			if (s.find({ { a,b - 1 }, {a,b} }) == s.end()) {
				s.insert({ { a,b }, { a,b - 1 } });
				s.insert({ { a,b - 1 }, { a,b } });
				answer++;
			}
		}
		else if (dirs[i] == 'D') {
			b--;
			if (a < -5 || a>5 || b < -5 || b>5) {
				b++;
				continue;
			}
			if (s.find({ {a,b+1} ,{ a,b } }) == s.end()) {
				s.insert({ {a,b + 1} ,{ a,b } });
				s.insert({ { a,b } ,{a,b + 1}});
				answer++;
			}
		}
		else if (dirs[i] == 'R') {
			a++;
			if (a < -5 || a>5 || b < -5 || b>5) {
				a--;
				continue;
			}
			if (s.find({ {a-1,b}, { a, b } }) == s.end()) {
				s.insert({ {a - 1,b}, { a, b } });
				s.insert({ {a,b}, { a-1, b } });
				answer++;
			}
		}
		else if (dirs[i] == 'L') {
			a--;
			if (a < -5 || a>5 || b < -5 || b>5) {
				a++;
				continue;
			}
			if (s.find({ {a+1,b}, { a,b } }) == s.end()) {
				s.insert({ {a + 1,b}, { a,b } });
				s.insert({ {a,b}, { a+1,b } });
				answer++;
			}
		}
		//cout << i << " " << answer << "\n";
	}


	return answer;
}