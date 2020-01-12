#include <iostream>
using namespace std;

int d[1010][1010];
int list[1010][1010];
int main() {

	int h, w, n;
	cin >> h >> w >> n;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++)
			cin >> list[i][j];
	}

	// N-1��° ��å���� ��� ����
	d[1][1] = n - 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (d[i][j] == 0)           // ������ �������� ��ŵ
				continue;

			d[i + 1][j] += d[i][j] / 2; // ������ �Ʒ���
			d[i][j + 1] += d[i][j] / 2; // ������ ������

			if (d[i][j] % 2 == 1) {  // Ȧ�� Ƚ����
				if (list[i][j] == 1)    // ���� ���¿� ���� ��,�� �߰�
					d[i][j + 1]++;
				else
					d[i + 1][j]++;
			}

			list[i][j] = (list[i][j] + d[i][j]) % 2; // ���������� ����
		}
	}

	// N��° ��å���
	int i = 1, j = 1;
	while (i <= h && j <= w) {
		if (list[i][j] == 1)
			j++;
		else
			i++;
	}

	cout << i << " " << j << "\n";
	return 0;
}