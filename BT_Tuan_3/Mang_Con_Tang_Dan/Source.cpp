
#include <iostream>

using namespace std;

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

void print_longest_increasing_sub_list(List& l)
{
    int ln = 1;
    int s = 1;
    Node* p = l.head;
    Node* r = l.head->next;
    while (r != NULL)
    {
        if (r->val >= p->val)
        {
            s += 1;
        }
        else
        {
            s = 1;
        }
        if (ln < s)
        {
            ln = s;
        }
        p = p->next;
        r = r->next;
    }
    cout << ln;
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

    print_longest_increasing_sub_list(l);


    return 0;
}
