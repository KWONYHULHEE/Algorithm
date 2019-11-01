#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100010;

vector <int> list[MAX];
vector <int> reverselist[MAX];
int n, m;

int time2[MAX], clock2 = 1;
int order[MAX], order_len = 0;  //���������� �ð��� ū������� ��� ���
int group[MAX], group_cnt = 1;
bool check[MAX], check2[MAX];

void get_time(int node) {

	check[node] = true;

	for (int i = 0; i < list[node].size(); i++) {
		int node2 = list[node][i];

		if (!check[node2]) {
			get_time(node2);
		}
	}

	time2[node] = clock2;
	clock2++;

	order[order_len++] = node;

}

void get_my_group(int node) {  //�׷� ��ȣ ��� 
	check2[node] = true;
	group[node] = group_cnt;

	for (int i = 0; i < reverselist[node].size(); i++) {
		int node2 = reverselist[node][i];

		if (!check2[node2]) {
			get_my_group(node2);
		}
	}
}
int main() {

	//Please Enter Your Code Here


	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		list[a].push_back(b);
		reverselist[b].push_back(a);


	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			get_time(i);
		}
	}

	for (int i = order_len - 1; i >= 0; i--) {
		//����ū ģ������ (���������� �مf���Ƿ� ���� ūģ���� ���� �����ִ� ��尡��)
		int node = order[i];

		if (!check2[node]) {
			get_my_group(node);
			group_cnt++;
		}

	}

	printf("%d\n", group_cnt - 1);
	return 0;
}