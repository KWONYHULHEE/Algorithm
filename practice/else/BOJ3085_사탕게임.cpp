#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 50;
int N;
string board[MAX];

int numOfCandy(){

	int result = 1;

	//¾ç ¿·

	for (int i = 0; i < N; i++){

		int temp = 1;

		for (int j = 0; j < N - 1; j++) {

			if (board[i][j + 1] == board[i][j])	temp++;
			else {
				result = max(result, temp);
				temp = 1;
			}
		}
		result = max(result, temp);
	}

	//À§ ¾Æ·¡

	for (int i = 0; i < N; i++){

		int temp = 1;

		for (int j = 0; j < N - 1; j++) {

			if (board[j + 1][i] == board[j][i]) temp++;
			else{
				result = max(result, temp);
				temp = 1;
			}

			result = max(result, temp);
		}

	}

	return result;

}



int main(void){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;


	for (int i = 0; i < N; i++)
		cin >> board[i];



	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++){

			//¾ç ¿· swap

			swap(board[i][j], board[i][j + 1]);
			result = max(result, numOfCandy());
			swap(board[i][j], board[i][j + 1]);

			//À§ ¾Æ·¡ swap

			swap(board[j][i], board[j + 1][i]);
			result = max(result, numOfCandy());
			swap(board[j][i], board[j + 1][i]);

		}
	}
	cout << result << "\n";

	return 0;

}

