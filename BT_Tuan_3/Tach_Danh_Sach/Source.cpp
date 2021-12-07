
#include <iostream>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::pair;

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
//Node* tim_kiem_dung_truoc(List l, int x)
//{
//    if (l.head == NULL) return NULL;
//    else
//    {
//        auto p = l.head;
//        while (p != l.tail && p->next->val != x)
//        {
//            p = p->next;
//        }
//        if (p == l.tail) return NULL;
//        else if (p->next->val == x) return p;
//    }
//    return NULL;
//}
//
//void delete_after_q(List& l, Node* q)
//{
//    if (q->next == l.tail)
//    {
//        delete l.tail;
//        q->next = NULL;
//        l.tail = q;
//    }
//    else if (q == l.tail);
//    else
//    {
//        auto p = q->next;
//        q->next = p->next;
//        delete p;
//    }
//}
//pair<List, List> split(List& l)
//{
//    List l2;
//    list_initializing(l2);
//    Node* b = l.head->next;
//    Node* a = l.head;
//    Node* r ;
//    while (b != NULL)
//    {
//        add_tail(l2, b->val);
//        a->next = b->next;
//        r = tim_kiem_dung_truoc(l, b->val);
//        delete_after_q(l, r);
//    }
//    return std::make_pair(l, l2);
//}

pair<List, List> split(List& l)
{
    List l2; list_initializing(l2);
    Node* a = l.head;
    Node* b = l.head->next;
    while (a != NULL && b != NULL)
    {
        if (l2.head == NULL)
            l2.head = l2.tail = b;
        else
        {
            l2.tail->next = b;
            l2.tail = b;
        }
        a->next = b->next;
        a = a->next;
        if (a == NULL)
            b->next = NULL;
        else
            b->next = a->next;
        b = b->next;
    }
    return std::make_pair(l, l2);
}

int main()
{
    List l; list_initializing(l);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int x;
    do {
        cin >> x;
        if (x != 0) add_tail(l, x);
        else break;
    } while (true);


    pair<List, List> ls = split(l);

    xuat(ls.first);
    xuat(ls.second);

    return 0;
}
