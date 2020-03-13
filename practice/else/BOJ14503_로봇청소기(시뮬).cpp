#include <iostream>
using namespace std;

int n, m, x, y, d;
int arr[100][100];
int res = 0;

int main() {
	
	cin >> n >> m;
	cin >> x >> y >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		int dx[] = { -1,0,1,0 };  //�ϵ�����
		int dy[] = { 0,1,0,-1 };

		if (arr[x][y] == 0) { //1. û��
			arr[x][y] = 2;
			res++;
		}

		//�������� ���鼭 û���Ұ��� �ִ��� Ȯ�� 
		int check = 0;
		for (int i = 0; i< 4; i++) {
			d = d - 1; //���ʹ���
			if (d < 0) d = 3;

			int temp_x = x + dx[d]; 
			int temp_y = y + dy[d];

			if (arr[temp_x][temp_y] == 0) { //û���Ұ�������
				x = temp_x; //�����̰�
				y = temp_y;
				check = 1; //1������ ����
				break;
			}
		}

		if (check == 1) continue; //1�����ΰ���

		//û���Ұ� ������
		int temp_d = d - 2;   //�ڷΰ���
		if (temp_d == -2) temp_d = 2;
		if (temp_d == -1) temp_d = 3;

		x = x + dx[temp_d];
		y = y + dy[temp_d];


		//�ڷΰ��µ� ���̰ų� û�ҵ������� ��
		if (arr[x][y] == 1) break; 
	}
	cout << res;
	return 0;
}