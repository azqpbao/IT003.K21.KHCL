#include <iostream>
using namespace std;
struct node {
	int val;
	node* next;
};
struct queue {
	node* head, * tail;
};
node* getNode(int x) {
	node* p = new node;
	if (p == NULL) return NULL;
	p->val = x;
	p->next = NULL;
	return p;
}
void init(queue& q) {
	q.head = q.tail = NULL;
}
bool Is_Empty(queue q) {
	if (q.head == NULL) return true;
	return false;
}
void push(queue& q, int x) {
	node* p = getNode(x);
	if (q.head == NULL) {
		q.head = q.tail = p;
	}
	else {
		q.tail->next = p;
		q.tail = p;
	}
}
void pop(queue& q, int& x) {
	if (q.head == NULL) {
		cout << "EMPTY" << endl;
	}
	else {
		x = q.head->val;
		auto p = q.head;
		q.head = q.head->next;
		delete p;
		cout << x << endl;
	}
}
void top(queue q, int& x) {
	if (q.head == NULL) {
		cout << "EMPTY" << endl;
	}

	else {
		x = q.head->val;
		cout << x << endl;
	}
}
int main() {
	queue q; init(q);
	int  x, a, b;
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	do {
		cin >> x;
		switch (x) {
		case 1:
			cin >> a;
			push(q, a);
			break;
		case 2:
			pop(q, a);
			break;
		case 3:
			top(q, a);
			break;
		}
	} while (x != 4);
	return 0;
}