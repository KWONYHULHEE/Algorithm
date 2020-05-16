#include <iostream>
#include <string>
using namespace std;

const int MAX = 64;

int N;
int arr[MAX][MAX];


void compress(int n, int x, int y){

	if (n == 1){

		cout << arr[x][y];
		return;

	}


	bool zero = true, one = true;

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] == 1) zero = false;
			else one = false;
		}
	}


	if (zero) cout << 0;
	else if (one) cout << 1;

	else{

		cout << "(";

		compress(n / 2, x, y);
		compress(n / 2, x, y + n / 2);
		compress(n / 2, x + n / 2, y);
		compress(n / 2, x + n / 2, y + n / 2); 

		cout << ")";

	}

	return;

}



int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;



	bool zero = true, one = true;

	for (int i = 0; i < N; i++){

		string s;
		cin >> s;


		for (int j = 0; j < N; j++)
			arr[i][j] = s[j] - '0';

	}


	compress(N, 0, 0);
	cout << "\n";

	return 0;

}