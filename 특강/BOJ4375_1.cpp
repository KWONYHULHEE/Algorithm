#include <iostream>
#include <vector>
using namespace std;


int main() {



	int n, answer, temp;

	while (cin>>n) {
		answer = 1;
		temp = 1;
		while (1) {

			if (temp%n== 0) {
				printf("%d\n", answer);
				break;
			}
			answer++;
			temp *= 10;
			temp++;
		
			temp = temp % n;
		
		}
	}

	dudwls

	return 0;
}




