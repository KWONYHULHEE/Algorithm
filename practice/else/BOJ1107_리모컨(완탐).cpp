#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 987654321;

//2 3 4 5 6 7 8 9를 입력 못하는 경우도 고려

const int MAX = 1000000 + 1;

int N, M;
vector<int> broken;


//해당 채널을 누르는 것이 가능한지 여부

//고장난 버튼을 누르면 false

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


//100에서 시작이 아닌 채널을 누르고 나서 +/-

int changeEntirely(){

	int result = INF;
	int similar = 0;

	for (int i = 0; i < MAX; i++){  //해당 채널을 누를 수 있다면

		if (possible(i)){

			int click = abs(N - i); //+/-을 몇 번 눌러야하는지 확인

			if (result > click){  //덜 클릭해도 된다면

				result = click;
				similar = i; //해당 숫자 저장

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
