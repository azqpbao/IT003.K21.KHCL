
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


List merge_2_sorted_lists(List& l, List& l2)
{
    Node* a = l.head;
    Node* b = l2.head;
    if (a == NULL) return l;
    if (b == NULL) return l2;
    List k; list_initializing(k);
    if (a->val < b->val)
    {
        add_tail(k, a->val);
        a = a->next;
    }
    else
    {
        add_tail(k, b->val);
        b = b->next;
    }
    while (a != NULL && b != NULL)
    {
        if (a->val < b->val)
        {
            add_tail(k, a->val);
            a = a->next;
        }
        else
        {
            add_tail(k, b->val);
            b = b->next;
        }

    }
    if (a == NULL)
    {
        while (b != NULL)
        {
            add_tail(k, b->val);
            b = b->next;
        }
    }
    if (b == NULL)
    {
        while (a != NULL)
        {
            add_tail(k, a->val);
            a = a->next;
        }
    }
    return  k;
}


int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List lists[2];

    for (int i = 0; i < 2; i++) {
        list_initializing(lists[i]);
        int x;
        do {
            cin >> x;
            if (x != 0) add_tail(lists[i], x);
            else break;
        } while (true);
    }

    List l = merge_2_sorted_lists(lists[0], lists[1]);

    xuat(l);

    return 0;
}
