#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 987654321;

//2 3 4 5 6 7 8 9�� �Է� ���ϴ� ��쵵 ���

const int MAX = 1000000 + 1;

int N, M;
vector<int> broken;


//�ش� ä���� ������ ���� �������� ����

//���峭 ��ư�� ������ false

bool possible(int num){

	if (num == 0) {

		if (find(broken.begin(), broken.end(), 0) == broken.end())	return true;
		else return false;

	}

	while (num){

		if (find(broken.begin(), broken.end(), num % 10) != broken.end()) return false;

		num /= 10;

	}

	return true;

}


//100���� ������ �ƴ� ä���� ������ ���� +/-

int changeEntirely(){

	int result = INF;
	int similar = 0;

	for (int i = 0; i < MAX; i++){  //�ش� ä���� ���� �� �ִٸ�

		if (possible(i)){

			int click = abs(N - i); //+/-�� �� �� �������ϴ��� Ȯ��

			if (result > click){  //�� Ŭ���ص� �ȴٸ�

				result = click;
				similar = i; //�ش� ���� ����

			}
		}
	}

	return result + to_string(similar).size();

}



int main(){

	cin >> N >> M;

	for (int i = 0; i < M; i++){

		int button;
		cin >> button;
		broken.push_back(button);

	}


	cout << min(abs(N - 100), changeEntirely()) << endl;

	return 0;

}
