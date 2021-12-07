#include <iostream>
using namespace std;
#define size 1000000
//const int size = 10000;
struct node {
	int val;
	node* next;
};
struct list {
	node* head, * tail;
};
node* get_node(int x) {
	node* p = new node;
	p->val = x;
	p->next = NULL;
	return p;
}
void add_tail(list& l, int x) {
	if (l.head == l.tail) l.head = l.tail = get_node(x);
	else {
		node* p = get_node(x);
		l.tail->next = p;
		l.tail = p;
	}
}
void delete_head(list& l) {
	if (l.head == NULL);
	else if (l.head == l.tail) {
		delete l.head;
		l.head = l.tail = NULL;
	}
	else {
		node* p = l.head;
		l.head = l.head->next;
		delete p;
	}
}
void delete_node(list& l, int x) {
	if (l.head->val == x) {
		delete_head(l);
	}
	else {
		node* p = l.head;
		while (p != NULL) {
			if (p->next->val == x) break;
			p = p->next;
		}
		if (p == NULL);
		else if (p->next == NULL) {
			delete l.tail;
			p->next = NULL;
			l.tail = p;
		}
		else {
			node* s = p->next;
			p->next = s->next;
			delete s;
		}
	}
}
node* find(list l, int x) {
	node* p = l.head;
	while (p != NULL) {
		if (p->val == x) return p;
		p = p->next;
	}
	return NULL;
}
bool search(list* l, int x) {
	int k = x % size;
	return find(l[k], x) != nullptr;
}
void insert(list*& l, int x) {
	int k = x % size;
	add_tail(l[k], x);
}
void delete_1(list*& l, int x) {
	int k = x % size;
	delete_node(l[k], x);
}
int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	list* T = new list[size];
	for (int i = 0; i < size; i++) T[i].head = T[i].tail = NULL;

	int x, ms;
	while (true) {
		cin >> x;
		if (x == 0) break;
		cin >> ms;
		if (x == 1) insert(T, ms);
		else if (x == 2) cout << search(T, ms) << "\n";
		else if (x == 3) delete_1(T, ms);
	}
	return 0;
}