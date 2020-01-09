#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	if (a > b) return true;
	else return false;
}

int main() {


	string n;
	cin >> n;
	int len = n.size();
	long long int sum = 0;
	bool flag = false;

	for (int i = 0; i < len; i++) {
		sum += (n[i]-'0');
		if (n[i]-'0' == 0) flag = true;
	}

	if (flag == true && sum % 3 == 0) {
		sort(n.begin(), n.end(),cmp);
		cout << n;
	}
	else cout << "-1";
	

	

	return 0;
}