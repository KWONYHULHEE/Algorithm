#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;

bool cmp(string a, string b) {
	return a > b;
}
int main() {


	cin >> n;
	set <string> s;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (s.find(a) == s.end()) {
			s.insert(a);
		}
		else {
			auto it = s.find(a);
			s.erase(it);
		}

	}

	vector <string> v;
	for (auto i: s) {
		v.push_back(i);
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}