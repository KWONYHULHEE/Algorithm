#include <stdio.h>

const int MAX = 100;
struct  Queue {
	int f, r;
	int capacity;
	int data[MAX];

	void create(int y) {
		capacity = y;
		f = 0;
		r = 0;
	}
	void push(int y) {
		if (r >= capacity)
			printf("Overflow\n");
		else {
			data[r] = y;
			r++;
		}
	}

	void pop() {
		if (r - f <= 0)
			printf("Underflow\n");
		else {
			data[f] = 0;
			f++;
		}
	}

	void front() {
		if (r - f <= 0)
			printf("NULL\n");
		else
			printf("%d\n", data[f]);
	}
};

int main() {

	Queue q;
	//Please Enter Your Code Here
	int n, m;
	int a, b;
	scanf("%d %d", &n, &m);
	q.create(n);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d", &b);
			q.push(b);
		}
		else if (a == 2) {
			q.pop();
		}
		else if (a == 3) {
			q.front();
		}
	}

	return 0;
}