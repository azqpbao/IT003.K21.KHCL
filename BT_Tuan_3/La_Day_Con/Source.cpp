
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

int length(List l)
{
    int s = 0;
    for (Node* it = l.head; it != NULL; it = it->next)
    {
        s += 1;
    }
    return s;
}
//void swap(Node* &a, Node* &b)
//{
//    Node* t = a; a = b; b = t;
//}
int is_subsequence(List l, List l2)
{
    Node* mom = l2.head;;
    Node* child = l.head;
    if (length(l) > length(l2))
    {
        mom = l.head;
        child = l2.head;
    }
    while (mom != NULL && child != NULL)
    {
        if (child->val == mom->val)
        {
            mom = mom->next;
            child = child->next;
        }
        else
        {
            mom = mom->next;
        }
    }
    if (child == NULL) return 1;
    if (mom == NULL) return 0;
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
            if (x != -1) add_tail(lists[i], x);
            else break;
        } while (true);
    }
    

    if (is_subsequence(lists[0], lists[1])) cout << "TRUE";
    else cout << "FALSE";


    return 0;
}


