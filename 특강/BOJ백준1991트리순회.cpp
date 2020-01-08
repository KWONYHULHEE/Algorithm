#include <cstdio>
#include <vector>
using namespace std;


vector<pair<char, bool>> tree[26]; 


void preorder(char x) {

	printf("%c", x);
	for (int i = 0; i < tree[x].size(); i++) {
		preorder(tree[x][i].first);
	}
}
void postorder(char x) {

	for (int i = 0; i < tree[x].size(); i++) {
		postorder(tree[x][i].first);
	}
	printf("%c", x);
}

void inorder(char x) {

	//자식이 존재하고 왼쪽 자식이라면

	if (tree[x].size() && tree[x][0].second)
		inorder(tree[x][0].first);

	printf("%c", x);

	//오른쪽 자식만 있다면

	if (tree[x].size() && !tree[x][0].second)

		inorder(tree[x][0].first);

	//양쪽 자식 다 있다면

	else if (tree[x].size() == 2)

		inorder(tree[x][1].first);
}

int main() {

	
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char a,b,c;
		scanf(" %c %c %c", &a,&b,&c);
		
		if (b != '.') {
			tree[a].push_back({ b,true });
		}
		if (c != '.') {
			tree[a].push_back({ c,false });
		}
		
	}

	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	printf("\n");




	return 0;
}