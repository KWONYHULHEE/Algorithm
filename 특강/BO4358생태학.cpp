#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();

	map<string, int> m;
	string species;
	int total = 0;


	while (getline(cin, species)) {   
		//�ԷµǴ� ���ڿ� ���� �� �������ִ� ���¿��� 
		//EOF���� ������ ���Ե� ���ڿ��� ������� �Է¹ޱ�

		++m[species];
		++total;
	}


	cout.precision(4); //�Ҽ��� 4�ڸ����� ���
	cout << fixed; //�Ҽ����� �������� ǥ��

	for (auto ele:m) {
		cout << ele.first<< " " << ((double)ele.second / total) * 100 << endl;
	}

	return 0;
}