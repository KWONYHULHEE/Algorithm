#include <stdio.h>
int n, m;
const int MAX = 100;


struct Queue {
	int data[MAX];
	int f, r;
	int capacity;
	int  numelement;

	void create(int y) {
		capacity = y;
		f = 0;
		r = 0;
		numelement = 0;
	}

	void push(int y) {

		if (numelement >= capacity)
			printf("Overflow\n");

		else {
			data[r++] = y;
			if (r >= MAX) r = 0;
			numelement++;
		}
	}

	void pop() {
		if (numelement <= 0)
			printf("Underflow\n");
		else {
			data[f++] = 0;
			if (f >= MAX) f = 0;
			numelement--;
		}
	}
	void front() {
		if (numelement <= 0)
			printf("NULL\n");
		else
			printf("%d\n", data[f]);
	}

};
int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &n, &m);
	Queue q;
	q.create(n);

	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
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


