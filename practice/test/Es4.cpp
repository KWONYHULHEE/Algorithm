#include <vector>
#include <string>
#include <map>
using namespace std;

struct Name {
	string first, middle, last;
};

Name name[1010];

string solution(string &S, string &C) {

	//email
	string email = "@";
	int csize = C.size();
	int ssize = S.size();

	for (int i = 0; i < csize; i++) {
		if (C[i] >= 'A'&&C[i] <= 'Z')
			C[i] = C[i] - 'A' + 'a';

		email += C[i];
	}

	email += ".com";


	//fullname
	vector<string> fullname;
	string add = "";
	for (int i = 0; i < ssize; i++) {

		if (S[i] == ';') {
			fullname.push_back(add);
			add = "";
			i++;
		}
		else if (i == ssize - 1) {
			add += S[i];
			fullname.push_back(add);
		}
		else add += S[i];

	}

	//first, middle, last 나누기
	string temp = "";
	string individual = "";
	int len = fullname.size();
	map <string, int> mp;
	string result;

	for (int i = 0; i < len; i++) {
		int cnt = 0;
		temp = "";
		int slen = fullname[i].length();
		for (int j = 0; j < slen; j++) {

			if (fullname[i][j] == ' ') {
				if (cnt == 0) {
					name[i].first = temp;
					cnt++;
					temp = "";
				}
				else if (cnt == 1) {
					name[i].middle = temp;
					cnt++;
					temp = "";
				}
			}
			else if (j == slen - 1) {

				temp += fullname[i][j];
				name[i].last = temp;
			}
			else {

				if (fullname[i][j] >= 'A' && fullname[i][j] <= 'Z') {
					char c = fullname[i][j] - 'A' + 'a';
					temp += c;
				}
				else if (fullname[i][j] == '-') continue;

				else temp += fullname[i][j];
			}

		}

		//완성

		string person = name[i].last + "_" + name[i].first;
		string num = "";

		auto it = mp.find(person);
		if (it == mp.end()) { //없으면
			individual = fullname[i] + " <" + person + email + ">";
			mp[person]++;
		}
		else {
			if (it->second >= 1) num = to_string((it->second + 1));
			mp[person]++;
			individual = fullname[i] + " <" + person + num + email + ">";
		}

		if (i != len - 1) result += individual + "; ";
		else result += individual;
	}


	return result;

}