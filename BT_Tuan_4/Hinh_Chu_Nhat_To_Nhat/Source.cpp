#include <iostream>
using namespace std;
struct node {
	int val;
	node* next;
};
struct stack {
	node* head;
};
node* getnode(int x) {
	node* p = new node;
	if (p == NULL) return NULL;
	p->val = x;
	p->next = NULL;
	return p;
}
void push(stack& s, int x) {
	node* p = getnode(x);
	if (s.head == NULL) s.head = p;
	else {
		p->next = s.head;
		s.head = p;
	}
}
void pop(stack& s) {
	if (s.head == NULL);
	else {
		auto p = s.head;
		s.head = p->next;
		delete p;
	}
}
void hinh_chu_nhat_to_nhat(int* a, int n, stack& s) {
	int b, c, ln = 0;
	int i = 0;
	while(i < n) {
		if (s.head == NULL || a[i] > a[s.head->val]) {
			push(s, i);
		}
		else {
			b = s.head->val;
			pop(s);
			if (s.head == NULL) {
				c = i;
			}
			else {
				c = i - s.head->val - 1;
			}
			ln = (c * a[b] > ln) ? c * a[b] : ln;
			i--;
		}
		i++;
	}
	cout << ln * 10;
}
int main() {
	int n;
	stack s; s.head = NULL;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	hinh_chu_nhat_to_nhat(a, n, s);
	return 0;
}