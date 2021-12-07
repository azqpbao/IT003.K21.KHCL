
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

void list_initializing(List& l) {
	l.head = l.tail = NULL;
}
Node* getnode(int x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->val = x;
		p->next = NULL;
		return p;
	}
}
void add_tail(List& l, int x)
{
	Node* p = new Node;
	p = getnode(x);
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void xuat(List& l) {
	Node* p = l.head;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
}


int length(List& l)
{
	if (l.head == NULL)
	{
		return 0;
	}
	else
	{
		l.head = l.head->next;
		return 1 + length(l);
	}

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
