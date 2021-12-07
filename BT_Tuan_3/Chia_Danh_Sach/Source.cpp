#include <iostream>
#include <tuple>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::get;
using std::tuple;
using std::make_tuple;

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

void join(List& l, List l2)
{
    if (l.head == NULL){
        l.head = l2.head;
        l.tail = l2.tail;
    }else if (l2.head == NULL);
    else {
        l.tail->next = l2.head;
        l.tail = l2.tail;
    }
}
void add(List& l, Node* p)
{
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}
tuple<List, List, List> partition(List& l, int x)
{
    List l1, l2, l3;
    l1.head = l1.tail = NULL;
    l2.head = l2.tail = NULL;
    l3.head = l3.tail = NULL;
    Node* a = l.head;
    while (a != NULL)
    {
        l.head =a->next;
        a->next = NULL;
        if (a->val < x){
           /* if (l1.head == NULL) {
                l1.head = l1.tail = a;
            }
            else {
                l1.tail->next = a;
                l1.tail = a;
            }*/
            add(l1, a);
        }
        else if (a->val > x){
            /*if (l3.head == NULL) {
                l3.head = l3.tail = a;
            }
            else {
                l3.tail->next = a;
                l3.tail = a;
            }*/
            add(l3, a);
        }
        else{
           /* if (l2.head == NULL) {
                l2.head = l2.tail = a;
            }
            else {
                l2.tail->next = a;
                l2.tail = a;
            }*/
            add(l2, a);
        }
        a = l.head;
    }
    l.head = l.tail = NULL;
    return make_tuple(l1, l2, l3);
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


    do {
        cin >> x;
        if (x == 0) break;

        auto ls = partition(l, x);

        xuat(std::get<0>(ls));
        xuat(std::get<1>(ls));
        xuat(std::get<2>(ls));


        join(l, std::get<0>(ls));
        join(l, std::get<1>(ls));
        join(l, std::get<2>(ls));

    } while (true);

    return 0;
}



