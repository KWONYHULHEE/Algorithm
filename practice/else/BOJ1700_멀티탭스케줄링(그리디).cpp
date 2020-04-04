/*
 �� ��Ʈ�� ������ ���� ���� �ִ� ������ �߿�
 ���߿� ���� �ʰ� ����ϴ� ������ ��Ʈ�� �A��.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100];
bool use[100];
int tab[100];

int main() {

	ios::sync_with_stdio(false); cin.tie(0);
	int n, nn;
	cin >> n >> nn;

	for (int i = 0; i < nn; i++) {
		cin >> arr[i];
		arr[i]--;
	}

	int ret = 0;
	int tabIdx = 0;

	for (int i = 0; i < nn; i++) {

		if (use[arr[i]]) continue;	//����ϴ� ��������        
								   
		else if (tabIdx < n) {		//��Ƽ�� ������ ����
			tab[tabIdx++] = arr[i];
			use[arr[i]] = true;
			continue;
		}


		ret++; // �� �ΰ��� ��츦 �����ϰ�� ���� �� �ۿ� ����.

		int port = 0;
		int farDistance = 0;

		//��Ƽ�ǿ� �����ִ� ���� �˻�
		for (int j = 0; j < n; j++) {
			int distance = 987654321;

			for (int k = i + 1; k < nn; k++) {
				if (tab[j] == arr[k]) {
					distance = k;
					break;
				}
			}

			if (distance > farDistance) { //���� ���߿� ���̴°ɷ� ������Ʈ
				port = j;
				farDistance = distance;
			}
		}

		//���� �����ִ� �� �߿� ���� �� �������� ��Ʈ���� ����
		use[tab[port]] = false;
		use[arr[i]] = true;
		tab[port] = arr[i];
	}

	cout << ret;

	return 0;
}
