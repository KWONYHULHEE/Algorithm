#include <stdio.h>

struct Stack {
	int data[100];
	int len = 0;
	int capacity = 0;

	void create(int y) {
		capacity = y;
	}
	void push(int y) {
		if (len >= capacity) printf("Overflow\n");
		else
			data[len++] = y;

	}
	void pop() {
		if (len <= 0) printf("Underflow\n");
		else {
			data[len - 1] = 0;
			len--;
		}
	}
	void top() {
		if (len <= 0) printf("NULL\n");
		else printf("%d\n", data[len - 1]);
	}

};

int main() {

	//Please Enter Your Code Here
	Stack s;

	int n, m;
	int k;
	int x;

	scanf("%d %d", &n, &m);
	s.create(n);


	for (int i = 0; i < m; i++) {

		scanf("%d", &k);
		if (k == 1) {
			scanf("%d", &x);
			s.push(x);
		}
		else if (k == 2)
			s.pop();
		else if (k == 3)
			s.top();


	}

	return 0;
}