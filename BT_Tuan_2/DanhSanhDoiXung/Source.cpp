
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


bool is_palindrome(List& l) 
{
	int s = 0;
	Node* p = l.head;
	while (p != NULL)
	{
		s += 1;
		p = p->next;
	}
	if (s == 1)
	{
		return true;
	}
	Node* prev = l.head;
	Node* current = l.head->next;
	l.head = current->next;
	prev->next = NULL;
	current->next = prev;
	int n = s / 2;
	for (int i = 2; i <= n - 1; i++)
	{
		prev = current;
		current = l.head;
		l.head = l.head->next;
		current->next = prev;
	}
	if (s % 2 == 0)
	{
		prev = l.head;
	}
	else
	{
		prev = l.head->next;
	}
	Node* r = current;
	while (r != NULL)
	{
		if (r->val != prev->val)
		{
			return false;
		}
		r = r->next;
		prev = prev->next;
	}
	return true;
}

int main()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	List l; list_initializing(l);

	int x;
	do {
		cin >> x;
		if (x != 0) add_tail(l, x);
		else break;
	} while (true);

	if (is_palindrome(l)) cout << "TRUE";
	else cout << "FALSE";
	cout << endl;

	return 0;
}
