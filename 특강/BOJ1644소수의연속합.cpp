#include <iostream>
#include <vector>
using namespace std;

int arr[4000010];
vector <int> v;

int main() {

	int n;
	scanf("%d", &n);
	int answer = 0;

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <=n; i++) {
		for (int j = 2; j <=n /i; j++) {
			arr[i*j] = 1;
		}
	}  //�Ҽ��� 0



	for (int i = 2; i <= n; i++) {  // N���� ��� �Ҽ��� �����Ѵ�
		if (arr[i] == 0) {
			v.push_back(i);
		}
	}

	int sum = 0, head = 0, tail = 0;    // �κ��չ���ó�� �������ͷ� N�� ������ �� ������ ī���� �Ѵ�

	for (int i = 0; i<v.size(); i++) {
		sum += v[head++];
		while (sum >n) {
			sum -= v[tail++];
		}
		if (sum == n) {
			//cout << arr[20];
			answer++;
		}
	}

	cout << answer;



	return 0;
}




