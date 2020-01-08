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
		//입력되는 문자열 수가 안 정해져있는 상태에서 
		//EOF까지 공백이 포함된 문자열을 행단위로 입력받기

		++m[species];
		++total;
	}


	cout.precision(4); //소수점 4자리까지 출력
	cout << fixed; //소수점을 고정시켜 표현

	for (auto ele:m) {
		cout << ele.first<< " " << ((double)ele.second / total) * 100 << endl;
	}

	return 0;
}