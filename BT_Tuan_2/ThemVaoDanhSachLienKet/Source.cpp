#include <iostream>
using  std::cin;
using  std::cout;
using  std::endl;

struct node
{
	int value;
	node* next;
};

struct list
{
	node* head;
	node* tail;
};

void initialize_list(list& a)
{
	a.head = NULL;
	a.tail = NULL;
}

node* getnode(int b)
{
	node* c = new node;
	if (c == NULL) return NULL;
	else
	{
		c->value = b;
		c->next = NULL;
		return c;
	}
}
void add_front(list& a, int b)
{
	node* c;
	c = getnode(b);
	if (a.head == NULL)
	{
		a.head = c;
		a.tail = c;
	}
	else
	{
		c->next = a.head;
		a.head = c;
	}
}

void add_back(list& a, int b)
{
	node* c;
	c = getnode(b);
	if (a.head == NULL)
	{
		a.head = c;
		a.tail = c;
	}
	else
	{
		a.tail->next = c;
		a.tail = c;
	}
}
int main()
{
	list a;
	initialize_list(a);
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int x, b, c;
	do {
		cin >> x;
		switch (x) {
		case 0:
			cin >> b;
			add_front(a, b);
			break;
		case 1:
			cin >> b;
			add_back(a, b);
			break;
		}
	} while (x != 3);

	for (node* it = a.head; it; it = it->next) {
		cout << it->value << " ";
	}
	return 0;
}

