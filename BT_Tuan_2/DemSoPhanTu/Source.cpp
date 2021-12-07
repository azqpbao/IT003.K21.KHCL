
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node {
	int val;
	Node* next;
};

struct List {
	Node* head, * tail;
	int x;
};

Node* getnode(int b)
{
	Node* c = new Node;
	if (c == NULL) return NULL;
	else
	{
		c->val = b;
		c->next = NULL;
	}
}

void list_initializing(List& l) {
	l.head = l.tail = NULL;
}
void add_tail(List& l, int x) 
{
	Node* c;
	c = getnode(x);
	if (l.head == NULL)
	{
		l.head = c;
		l.tail = c;
	}
	else
	{
		a.tail->next = c;
		a.tail = c;
	}
}

void xuat(List& l) 
{
	Node *c;
	c = l.head;
	while (c != NULL)
	{
		cout << c->val << endl;
		c = c->next;
	}
}

int length(List& l)
{
	Node* p = l.head;
	int s = 0;
	while (p != NULL)
	{
		s += 1;
		p = p->next;
	}
	return s;
}




int main()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	List l;

	list_initializing(l);
	int x;
	do {
		cin >> x;
		if (x != -1) add_tail(l, x);
		else break;
	} while (true);

	cout << length(l);

	return 0;
}
