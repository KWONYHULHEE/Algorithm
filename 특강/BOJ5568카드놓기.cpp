#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, k;
vector <int> arr;
vector <int> res;
set <string> st;
bool check[30];
void solve(int x) {

	if (x == k) {

		string s; //완성된 숫자
		string change; //이어붙일 숫자
		for (int i = 0; i < res.size(); i++) { //선택한 숫자를 이어붙인다.
			change = to_string(res[i]);
			s += change;
		}
		st.insert(s); //만든 숫자 삽입
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!check[i]) {
				check[i] = true;
				res.push_back(arr[i]);
				solve(x + 1);
				check[i] = false;
				res.pop_back();
			}
		}
	}
}

int main() {

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}

	solve(0);

	printf("%d", st.size());
	return 0;
}