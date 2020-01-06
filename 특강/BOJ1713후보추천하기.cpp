#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Recommend {
	int time;
	int rec;
};

int arr[1010];
Recommend str[30];

int main() {


	int n;
	int k;

	scanf("%d", &n);

	scanf("%d", &k);


	for (int i = 0; i < k; i++) {
		int num;
		scanf("%d", &num);

		arr[num]++;

		bool rep = true;

		for (int j = 0; j < n; j++) {

			if (str[j].rec == 0) {
				str[j].rec = num;
				str[j].time = i;
				rep = false;
				break;
			}

			else if (str[j].rec == num) {
				rep = false;
				break;
			}
		}

		if (rep) {

			int index = 0;

			for (int j = 1; j < n; j++) {

				if (arr[str[j].rec] == arr[str[index].rec]) {

					if (str[j].time < str[index].time)
						index = j;
				}


				else if (arr[str[j].rec] < arr[str[index].rec])

					index = j;


			}
			arr[str[index].rec] = 0;

			str[index].time = i;

			str[index].rec = num;

		}

	}

	vector <int>  result;

	for (int i = 0; i < n; i++)
	{
		result.push_back(str[i].rec);
	}

	sort(result.begin(), result.end());


	for (int i = 0; i < n; i++)
		printf("%d ", result[i]);



	return 0;
}