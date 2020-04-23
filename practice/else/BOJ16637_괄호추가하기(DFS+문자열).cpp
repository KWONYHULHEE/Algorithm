#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
int num[20];
char oper[20];
int cut;
int ans = -987654321;

int cal(int num1, int num2, char op) {
	if (op == '+') {
		return num1 + num2;
	}
	else if (op == '-') {
		return num1 - num2;
	}
	else if (op == '*') {
		return num1 * num2;
	}
}
void dfs(int idx, int result) {

	if (idx >= cut) {
		if (ans < result) ans = result;
		return;
	}

	int temp = cal(result, num[idx + 1], oper[idx]);
	dfs(idx + 1, temp);

	if (idx + 1 < cut)
	{
		int after_temp = cal(num[idx + 1], num[idx + 2], oper[idx + 1]);
		int now_temp = cal(result, after_temp, oper[idx]);
		dfs(idx + 2, now_temp);
	}
	

}
int main() {

	cin >> n;
	cut = n / 2;
	for (int i = 0; i < cut; i++) {
		cin >> num[i] >> oper[i];
	}
	cin >> num[cut];


	dfs(0, num[0]);
	
	cout << ans << "\n";
	return 0;
}