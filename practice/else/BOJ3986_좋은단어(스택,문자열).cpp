#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;


int main() {


	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		stack <char> s1;
		stack <char> s2;
		string a;
		cin >> a;
		for (int j = 0; j < a.size(); j++) {
			s1.push(a[j]);
		}
		for (int j = 0; j < a.size(); j++) {
			if (s2.empty() || s2.top() != s1.top())
			{
				s2.push(s1.top());
				s1.pop();
			}
			else if (s2.top() == s1.top()) {
				s2.pop();
				s1.pop();
			}
		}

		if (s1.empty() && s2.empty()) {
			cnt++;
		}
	}
	
	
	cout << cnt;

	return 0;
}