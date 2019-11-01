#include <stdio.h>
#include <string.h>

struct stack {
	int alpha[30];
	int length = 0;
	int capacity = 0;

	void create(int x) {
		capacity = x;
	}

	void push(int x) {
		alpha[length++] = x;
	}

	void pop() {
		length--;
	}

	int top() {
		if (length == 0) {
			return -1;
		}
		return alpha[length - 1];
	}
};

int main() {
	stack s;
	char dish[30];
	int result[60];
	int index = 0;
	int cnt = 0;

	scanf("%s", dish);

	for (int i = 0; i < strlen(dish); i++) {
		while (dish[i] != s.top() + 'a') {
			if (cnt > strlen(dish)) {
				printf("impossible");
				return 0;
			}
			s.push(cnt++);
			result[index++] = 1;
		}
		s.pop();
		result[index++] = 2;
	}
	for (int i = 0; i < index; i++) {
		if (result[i] == 1) {
			printf("push\n");
		}
		else {
			printf("pop\n");
		}
	}
	return 0;
}