#include <cstdio>
#include <vector>
using namespace std;


int main() {

	int num = 1;

	vector <bool> res;
	int arr[50];

	while (1) {

		vector <int> tree[26];
		int maxvalue = -1;
		int node = 0;
		int ver = 0;
		int cnt[26] = { 0, };

		while (1) {
			int a, b;
			scanf("%d %d", &a, &b);

			if (a < 0 && b < 0) {

				for (int i = 0; i < res.size(); i++) {
					if (res[i] == true) printf("Case %d is a tree.\n", i + 1);
					else if (res[i] == false) printf("Case %d is not a tree.\n", i + 1);
				}


				return 0;
			}

			if (a == 0 && b == 0)
				break;


			if (a > maxvalue) maxvalue = a;
			if (b > maxvalue) maxvalue = b;

			tree[a].push_back(b);
			cnt[a]++;
			cnt[b]++;

		}

		for (int i = 1; i <= maxvalue; i++)
			if (cnt[i] != 0) node++;


		for (int i = 1; i <= maxvalue; i++)
			ver += tree[i].size();


		//printf("\n%d %d\n", node,ver);

		if (node == ver + 1) res.push_back(true);
		else if (ver == 0) res.push_back(true);
		else res.push_back(false);

	}



	return 0;
}