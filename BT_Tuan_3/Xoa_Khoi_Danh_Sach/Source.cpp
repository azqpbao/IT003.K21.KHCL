#include <iostream>
using  std::cin;
using  std::cout;
using  std::endl;
using std::ios_base;
struct node
{
	int val;
	node* next;
};
struct list
{
	node* head, * tail;
};
void init(list& l)
{
	l.head = l.tail = NULL;
}
node* getnode(int x)
{
	node* p = new node;
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
void add_head(list& l, int x)
{
	node* p;
	p = getnode(x);
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
void add_tail(list& l, int x)
{
	node* p;
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
int tim_kiem(list l, int y, node*& q)
{
	for (q = l.head; q != NULL; q = q->next)
	{
		if (q->val == y)
		{
			return 1;
		}
	}
	return 0;
}
void add_after_q(list& l, int x, node* q)
{
	if (q == l.tail)
	{
		add_tail(l, x);
	}
	else
	{
		node* p = getnode(x);
		p->next = q->next;
		q->next = p;
	}
}
void delete_after_q(list& l, node* q)
{
	if (q->next == l.tail)
	{
		delete l.tail;
		q->next = NULL;
		l.tail = q;
	}
	else if (q == l.tail);
	else
	{
		auto p = q->next;
		q->next = p->next;
		delete p;
	}
}
void delete_head(list& l) {
	if (l.head == NULL);
	else if (l.head == l.tail)
	{
		delete l.head;
		l.head = NULL;
		l.tail = NULL;
	}
	else
	{
		auto p = l.head;
		l.head = l.head->next;
		delete p;
	}
}
node* tim_kiem_dung_truoc(list l, int x)
{
	if (l.head == NULL) return NULL;
	else
	{
		auto p = l.head;
		while (p != l.tail && p->next->val != x)
		{
			p = p->next;
		}
		if (p == l.tail) return NULL;
		else if (p->next->val == x) return p;
	}
	return NULL;
}
int main()
{
	list a;
	init(a);
	int x, b, c;
	do {
		cin >> x;
		switch (x) {
		case 0:
			cin >> b;
			add_head(a, b);
			break;
		case 1:
			cin >> b;
			add_tail(a, b);
			break;
		case 2:
			node * q;
			cin >> c >> b;
			if (tim_kiem(a, c, q) == 1)
			{
				add_after_q(a, b, q);
			}
			else
			{
				add_head(a, b);
			}
			break;
		case 3:
			cin >> b;
			if (a.head == NULL);
			else if (a.head->val == b)
			{
				delete_head(a);
			}
			else
			{
				auto q = tim_kiem_dung_truoc(a, b);
				if (q == NULL);
				else delete_after_q(a, q);
			}
			break;
		case 5:
			delete_head(a);
			break;
		}
	} while (x != 6);

	for (node* it = a.head; it; it = it->next) {
		cout << it->val << " ";
	}
	return 0;
}