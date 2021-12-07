#include <iostream>
using namespace std;
struct node {
	int val;
	node* next;
};
struct stack {
	node* top;
};
node* getNode(int x) {
	node* p = new node;
	if (p == NULL) {
		return NULL;
	}
	p->val = x;
	p->next = NULL;
	return p;
}
void init(stack& s) {
	s.top = NULL;
}
bool Is_Empty(stack s) {
	if (s.top == NULL) {
		/*cout << "EMPTY" << endl;*/
		return true;
	}
	return false;
}
void push(stack& s, int x) {
	node* p = getNode(x);
	if (p == NULL) cout << "EMPTY" << endl;;
	if (s.top == NULL) {
		s.top = p;
	}
	else {
		p->next = s.top;
		s.top = p;
	}
}
void pop(stack& s, int& x) {
	if (Is_Empty(s) == true) {
		cout << "EMPTY" << endl;
	}
	else {
		x = s.top->val;
		auto p = s.top;
		s.top = p->next;
		cout << x << endl;
	}
}
void top(stack s, int& x) {
	if (Is_Empty(s) == true) {
		cout << "EMPTY" << endl;
	}
	else {
		x = s.top->val;
		cout << x << endl;
	}
}
int main() {
	stack s; init(s);
	int  x, a, b;
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	do {
		cin >> x;
		switch (x) {
		case 1:
			cin >> a;
			push(s, a);
			break;
		case 2:
			pop(s, a);
			break;
		case 3:
			top(s, a);
			break;
		}
	} while (x != 4);
	return 0;
}