#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int idx, l = 0, r = 0, x, y;
}b[10001];

struct move {
	int l, r;
}m[10001];

bool cmp(Node a, Node b) {
	if (a.y > b.y) return true;
	else if (a.y < b.y) return false;
	else {
		return a.x < b.x;
	}
}
int num;
void makeTree(int root) {

	for (int i = 2; i <= num; i++) {
		int cur = root;
		while (1) {
			if (b[i].x < b[cur].x) {
				if (b[cur].l == 0) {
					b[cur].l = i;
					break;
				}
				else
					cur = b[cur].l;
			}
			else {
				if (b[cur].r == 0) {
					b[cur].r = i;
					break;
				}
				else
					cur = b[cur].r;
			}
		}
	}
}
vector<int> pre;
void preOrder(int cur) {
	if (cur == 0) return;
	pre.push_back(cur);
	preOrder(m[cur].l);
	preOrder(m[cur].r);
}
vector<int> pos;
void postOrder(int cur) {
	if (cur == 0) return;
	postOrder(m[cur].l);
	postOrder(m[cur].r);
	pos.push_back(cur);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	num = nodeinfo.size();

	for (int i = 1; i <= nodeinfo.size(); i++) {
		b[i].x = nodeinfo[i - 1][0];
		b[i].y = nodeinfo[i - 1][1];
		//cout << nodeinfo[i - 1][0] << ' ' << nodeinfo[i - 1][1] << '\n';
		b[i].idx = i;
	}

	sort(b + 1, b + num + 1, cmp); //1. y좌표 큰순, 2. x좌표 작은순

	makeTree(1); // root의 노드 번호

	for (int i = 1; i <= num; i++) {
		m[b[i].idx].l = b[b[i].l].idx;
		m[b[i].idx].r = b[b[i].r].idx;
	}

	preOrder(b[1].idx);
	postOrder(b[1].idx);

	answer.push_back(pre);
	answer.push_back(pos);
	return answer;
}


