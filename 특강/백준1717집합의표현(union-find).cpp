#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector <int> res;
int parent[1000010];

/*

union - find 이용

*/
int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x]=find(parent[x]);  //경로압축
}

void U(int a, int b) {
	 a = find(a);
	 b = find(b);

	parent[a] = b;
}


int main()
{

	

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		parent[i]=i;


	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b,&c);


		if (!a) {
			U(b, c);
		}
		else {
			if (find(b) == find(c)) printf("YES\n");
			else printf("NO\n");
		}
	}




	return 0;
}