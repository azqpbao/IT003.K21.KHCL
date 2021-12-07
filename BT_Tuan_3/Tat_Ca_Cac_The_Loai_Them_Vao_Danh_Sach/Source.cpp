#include <iostream>
using namespace std;
struct node
{
	int val;
	node* next;
};
struct list
{
	node *head, * tail;
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
int tim_kiem(list l, int y, node *q)
{
	q = l.head;
	for (; q != NULL; q = q->next)
	{
		if (q -> val == y)
		{
			return 1;
		}
	}
	return 0;
}
void add_after_q(list& l, int x, node *q )
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




int main()
{
	list a; 
	init(a);
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
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
	} while (x != 3);

	for (node* it = a.head; it; it = it->next) {
		cout << it->val << " ";
	}
	return 0;
}