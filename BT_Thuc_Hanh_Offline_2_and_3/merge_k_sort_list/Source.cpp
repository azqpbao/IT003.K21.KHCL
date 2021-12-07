
#include <iostream>
#include <algorithm>

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
/*
Node* merge_list(Node* head1, Node* head2)
{
	Node* result = NULL;
	if (head1 == NULL)
		return head1;
	if (head2 == NULL)
		return head2;
	Node* p = head1;
	Node* q = head2;
	Node* s = NULL;
	if (p && q)
	{
		if (p->val <= q->val)
		{
			s = p;
			p = s->next;
		}
		else
		{
			s = q;
			q = s->next;
		}
	}
	result = s;
	while (p && q)
	{
		if (p->val <= q->val)
		{
			s->next = p;
			s = p;
			p = s->next;
		}
		else
		{
			s->next = q;
			s = q;
			q = s->next;
		}

	}
	if (p == NULL) s->next = q;
	if (q == NULL) s->next = p;
	return result;
}
*/
Node* merge(Node* l, Node* r) {
	if (!l)
		return r;
	if (!r)
		return l;
	Node* p;
	if (l->val <= r->val) {
		p = l;
		l = p->next;
	}
	else {
		p = r;
		r = p->next;
	}
	Node* s = p;
	while (!l && !r) {
		if (l->val <= r->val) {
			p->next = l;
			p = l;
			l = p->next;
		}
		else {
			p->next = r;
			p = r;
			r = p->next;
		}
	}
	if (!l) p->next = r;
	else if (!r) p->next = l;
	return s;
}

List merge_k_sorted_lists(List* lists, int k)
{
	for (int i = 1; i < k; i = i * 2) {
		for (int j = 0; j < k; j = j + i * 2) {
			if ((k - j) < i * 2) {
				lists[j - i * 2].head = merge(lists[j - i * 2].head, lists[j].head);
				k -= (k - j);
				break;
			}
			lists[j].head = merge(lists[j].head, lists[j + i].head);
		}
	}
	return lists[0];
}


int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int k; cin >> k;
    List* lists = new List[k];

    for (int i = 0; i < k; i++) {
        list_initializing(lists[i]);
        int x;
        do {
            cin >> x;
            if (x != 0) add_tail(lists[i], x);
            else break;
        } while (true);
    }

    List l = merge_k_sorted_lists(lists, k);

    xuat(l);

    return 0;
}


