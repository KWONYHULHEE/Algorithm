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

		string s; //�ϼ��� ����
		string change; //�̾���� ����
		for (int i = 0; i < res.size(); i++) { //������ ���ڸ� �̾���δ�.
			change = to_string(res[i]);
			s += change;
		}
		st.insert(s); //���� ���� ����
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