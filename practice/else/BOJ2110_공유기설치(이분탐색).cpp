#include<iostream>
#include<algorithm>
using namespace std;

int N, C;
const int MAX_SIZE = 200001;
int arr[MAX_SIZE];

bool check(int x) {

	int cnt = 1;    // 0��°���� ������ ��ġ�ߴٰ� �����ϰ� ����
	int start = arr[0];    // 0�� ������ ��ġ�����ϱ� ���������� �ΰ�, mid���� ũ�ų� ���� �������� ã����, �� ���� ������ ��ġ.

	for (int i = 1; i < N; i++)
	{
		if (arr[i] - start >= x) {
			start = arr[i];
			cnt++;
		}
	}
	// ������ ������ ���� ��� �ľǵ�.

	if (cnt >= C)    // ��ġ�� ������ ������ ��ġ ���� Ƚ������ ũ�ų� ������
	{
		return true;
	}
	else return false;

}
int main() {

	cin.sync_with_stdio(false);
	cin.tie(NULL);

	int MAX = 0;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		MAX = MAX < arr[i] ? arr[i] : MAX;
	}
	sort(arr, arr + N);    // ����

	int left = 1;
	int right = MAX;
	int MAX_len = 0;

	// �̺� Ž������ ���� �� �Ÿ��� ���Ѵ�.
	while (left <= right) {

		int mid = (left + right) / 2;    // �߰������� ����
	
		if(check(mid)){
			MAX_len = mid;
			left = mid + 1; //�Ÿ��� �÷����ߴ�
		}
		else right = mid - 1;  //�Ÿ��� �������ߴ�
	}
	cout << MAX_len << "\n";

	return 0;
}