#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	multimap <int, int> m;
	set<int> check;
	string temp;
	bool flag = false;
	int cnt = 0;
	bool start = false;
	vector <int> v;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '{' || s[i] == '}' || s[i] == ',') {
			
			if (s[i] == '{') {
				start = true;
				temp = "";
			}
			if (s[i] == ',') {
				if (start) {
					v.push_back(stoi(temp));
					temp = "";
				}
			}
			if (s[i] == '}') {
				if(temp!="") v.push_back(stoi(temp));
				for (int i = 0; i < v.size(); i++) {
					m.insert({ v.size(),v[i] });
				}
				v.clear();
				temp = "";
				start = false;
			}

		}
		else {	
				temp += s[i];
		}
	}

	for (auto k : m) {
		int size = check.size();
		check.insert(k.second);
		if (size != check.size()) {
			answer.push_back(k.second);
		}
	}


	return answer;
}