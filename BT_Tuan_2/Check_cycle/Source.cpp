
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
	unsigned int val;
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

bool check_cycle(List l) {
	Node* r = l.head;
	Node* s = l.head->next;
	if (l.head == NULL)
	{
		return false;
	}
	while (s->next != NULL)
	{
		r = r->next;
		s = s->next->next;
		if (s == NULL || r == NULL)
		{
			return false;
		}
		if (s == r)
		{
			return true;
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int n; cin >> n;

	//Input list
	List l; list_initializing(l);
	int x;
	do {
		cin >> x;
		add_tail(l, x);
	} while (x != 0);


	//Create a loop if input call for it
	int i, j;
	cin >> i >> j;
	x = i <= j;

	if (x) {
		Node* pi, * pj, * p = l.head;
		for (int c = 0; p != NULL;) {
			if (c == i) pi = p;
			if (c == j) pj = p;

			p = p->next;
			c++;
		}
		pj->next = pi;
	}

	if (check_cycle(l) != x) cout << "WRONG";

	//All the node before the start of the loop must remain intact
	Node* p = l.head;
	for (i = 0; i <= j; i++, p = p->next) {
		cout << p->val << endl;
	}

	return 0;
}
