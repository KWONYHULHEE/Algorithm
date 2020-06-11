#include <iostream>
#include <string>
using namespace std;
int main() {

	string input;
	cin >> input;
	int level = 0;
	bool big = false;
	bool small = false;
	bool num = false;
	bool special = false;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') big = true;
		else if (input[i] >= 'A' && input[i] <= 'Z') small = true;
		else if (input[i] >= '0' && input[i] <= '9') num = true;
		else special = true;
	}

	if (big) level++;
	if (small) level++;
	if (num) level++;
	if (special) level++;

	if (input.size() >= 10) level++;

	cout << "LEVEL" << level << "\n";

	return 0;
}