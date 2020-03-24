#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {
	int begin; // ȸ�� ����
	int end; // ȸ�� ��
};

bool cmp(Time f, Time s) {
	if (f.end == s.end)
		return f.begin < s.begin; // ����ð��� ���ٸ�, ���۽ð��� ���� ��
	else
		return f.end < s.end; // ���� �ʴٸ�, ����ð��� ���������� ����
}

int main() {
	int N;
	cin >> N;

	vector<Time> t(N);
	for (int i = 0; i < N; i++) {
		cin >> t[i].begin >> t[i].end;
	}

	sort(t.begin(), t.end(), cmp); // ����

	int cnt = 0; // ȸ�� ������ ��
	int n = 0; // ȸ�� �������� ����

	for (int i = 0; i < t.size(); i++) {
		if (n <= t[i].begin) { // ȸ�� ���� ������ ���� ȸ�� ������������ ������
			n = t[i].end; // n�� ���� ȸ�� ���� ���� ����
			cnt++; // ȸ�� ���ɼ� ����
		}
	}

	cout << cnt << endl;
}
