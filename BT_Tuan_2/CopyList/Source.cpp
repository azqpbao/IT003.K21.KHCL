#include <iostream>
#include <cstdlib>
#include <ctime>

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

Node* getnode(int x)
{
	Node* p = new Node;
	if(p==NULL)
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

void copy(List& l, List& l2)
{
	Node* q = new Node;
	for (Node* it = l.head; it != NULL; it = it->next)
	{
		int x = it->val;
		q = getnode(x);
		add_tail(l2, x);
	}
}
int main()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	List l; list_initializing(l);
	//Read list
	int x;
	do {
		cin >> x;
		add_tail(l, x);
	} while (x != 0);

	List l2; list_initializing(l2);
	copy(l, l2);

	Node* p = l.head, * q = l2.head;
	while (p != NULL) {
		if (p == q || p->val != q->val) cout << "WRONG";
		cout << p->val << endl;
		p = p->next;
		q = q->next;
	}

	return 0;
}
