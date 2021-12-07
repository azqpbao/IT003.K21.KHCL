
#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};

struct List {
	Node* head, * tail;
};

void list_initializing(List& l) {
	l.head = l.tail = NULL;
}
void add_tail(List& l, int x) {
	Node* p = new Node;
	p->val = x;
	p->next = NULL;

	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else {
		l.tail->next = p;
		l.tail = p;
	}
}


void xuat(List& l) {
	for (Node* p = l.head; p != NULL; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}

// 1 2 3 4 5
//  null 1
void reverse_list(List& l)
{
	Node* previous= l.head;
	Node* current = l.head->next;
	l.head = current->next;
	previous->next= NULL;
	current->next = previous;
	while (l.head->next != NULL)
	{
		previous = current;
		current = l.head;
		l.head = l.head->next;
		current->next = previous;
	}
	l.head->next = current;
}


int main()
{
	List l; list_initializing(l);
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int x;
	do {
		cin >> x;
		if (x != 0) add_tail(l, x);
		else break;
	} while (true);

	for (int i = 0; i < 51; i++) reverse_list(l);

	xuat(l);

	return 0;
}




