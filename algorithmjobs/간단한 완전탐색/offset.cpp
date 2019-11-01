#include <iostream>
using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int main() {

	//Please Enter Your Code Here
	int arr[10][10];
	int str[10][10];

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			arr[i][j] = 10;
			str[i][j] = 10;
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> arr[i][j];
			str[i][j] = arr[i][j];
		}
	}

	int cnt = 0;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			for (int k = 0; k < 4; k++) {
				if (arr[i][j] < arr[i + dx[k]][j + dy[k]]) cnt++;
			}
			if (cnt == 4) str[i][j] = -1;
			// cout<<cnt<<endl;
			cnt = 0;
		}
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (str[i][j] == -1) cout << "* ";
			else cout << str[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}