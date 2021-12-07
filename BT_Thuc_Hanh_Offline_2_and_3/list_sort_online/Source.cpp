
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

struct List {
    Node* head, * tail;
    List() {
        head = NULL;
        tail = NULL;
    }
};

Node* create_node(int x) {
    Node* p = new Node;
    p->value = x;
    p->next = NULL;

    return p;
}

void add(List& l, int x) {
    Node* p = create_node(x);
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else if (x <= l.head->value) {
        p->next = l.head;
        l.head = p;
    }
    else if (x >= l.tail->value) {
        l.tail->next = p;
        l.tail = p;
    }
    else {
        for (Node* i = l.head; i != NULL; i = i->next) {
            if (i->next->value > x) {
                p->next = i->next;
                i->next = p;
                break;
            }
        }
    }
}

void xuat(List l, int x) {
    for (int i = 0; i < x; i++) {
        cout << l.head->value << " ";
        l.head = l.head->next;
    }
    cout << "\n";
}
void xuat(List l) {
    while (l.head != NULL) {
        cout << l.head->value << " ";
        l.head = l.head->next;
    }
    cout << "\n";
}
int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List a;

    int x, b;
    do {
        cin >> x;
        switch (x) {
        case 0:
            cin >> b;
            add(a, b);
            break;
        case 1:

            cin >> b;
            xuat(a, b);
            cout << endl;
            break;
        case 2:
            xuat(a);
            cout << endl;
        }
    } while (x != 3);
}

