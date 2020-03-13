#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> v;
vector <string> res;
int n;


int main() {


	cin >> n;

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		v.push_back(a);
	}
	
	if (n == 1) {
		for (int i = 0; i < 1; i++) {
			cout << v[i];
		}

		return 0;
	}

	string temp;
	for (int i = 0; i < v[0].size(); i++) {
		string temp = v[0].substr(i, 1);
		bool flag = false;
		string value;
		for (int j = 1; j < n; j++) {
			string k = v[j].substr(i, 1);
			if (temp == k) {
				value = temp;
				flag = true;
			}
			else {  //하나라도 다르면 물음푱 , 멈추기
				res.push_back("?");
				flag = false;
				break;
			}
		}
		if (flag == true) {
			res.push_back(value);
		}
		
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}


	return 0;
}