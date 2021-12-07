#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
};

Node* create_node(int x) {
    Node* p = new Node;
    p->value = x;
    p->next = NULL;

    return p;
}
struct list {
    Node* head, * tail;
};
void init(list& l) {
    l.head = l.tail = NULL;
}
void _0(list& l, int x) {
    Node* p = create_node(x);
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else {
        p->next = l.head;
        l.head = p;
    }
}
void _1(list& l, int x) {
    Node* p = create_node(x);
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}
void _2(list& l, int x, int y) {
    Node* p = l.head;
    for (; p != NULL; p = p->next) {
        if (p->value == x) {
            break;
        }
    }
    if (p == NULL) _0(l, y);
    else if (p->next == NULL) _1(l, y);
    else {
        Node* s = create_node(y);
        s->next = p->next;
        p->next = s;
    }
}
void go_to_another_list(list& l, list& l1) {
    Node* p = l.head;
    if (l.head == l.tail && l1.head != NULL) {
        l.head = l.tail = NULL;
        l1.tail->next = p;
        l1.tail = l1.tail->next;
    }
    else if (l.head == NULL)
        return;
    else if (l1.head == NULL) {
        l.head = l.head->next;
        p->next = NULL;
        l1.head = l1.tail = p;
    }
    else {
        l.head = l.head->next;
        p->next = NULL;
        l1.tail->next = p;
        l1.tail = l1.tail->next;
    }
}
void partition_of_dutch_national_flag(list &l, list& l1, list& l2, list& l3) {
    int pivot = l.head->value;
    while (l.head != NULL) {
        if (l.head->value < pivot) go_to_another_list(l, l1);
        else if (l.head->value == pivot) go_to_another_list(l, l2);
        else go_to_another_list(l, l3);
    }
}
void add_list(list& l, list l1) {
    if (l1.head == NULL) return;
    if (l.head == NULL) {
        l.head = l1.head;
        l.tail = l1.tail;
    }
    else {
        l.tail->next = l1.head;
        l.tail = l1.tail;
    }
}
void quick_sort(list& l) {
    if (l.head == l.tail || l.head == NULL) {
        return;
    }
    list l1, l2, l3;
    init(l1); init(l2); init(l3);
    partition_of_dutch_national_flag(l, l1, l2, l3);
    quick_sort(l1);
    quick_sort(l3);
    add_list(l, l1); add_list(l, l2); add_list(l, l3);
    
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    list l; init(l);
    int n;
    int x, y;
    do {
        cin >> n;
        switch (n) {
        case 0:
            cin >> x;
            _0(l, x);
            
            break;
        case 1:
            cin >> x;
            _1(l, x);
            
            break;
        case 2:
            cin >> x;
            cin >> y;
            _2(l, x, y);
            
            break;
        }
    } while (n != 3);
    Node* p = l.head;
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << "\n";
    quick_sort(l);
    Node* r = l.head;
    while (r != NULL) {
        cout << r->value << " ";
        r = r->next;
    }
    return 0;
}