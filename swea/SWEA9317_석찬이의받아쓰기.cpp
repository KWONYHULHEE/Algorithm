#include <iostream>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string a;
		string b;

		cin >> a;
		cin >> b;
		int cnt = 0;
		
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i]) {
					cnt++;
				}
		}

		cout <<"#"<<t<<" "<<cnt<< endl;

	}



	return 0;
}