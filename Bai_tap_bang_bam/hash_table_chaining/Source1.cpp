#include <iostream>
using namespace std;
const int size = 1000000;

struct node {
    int val;
    node* next;
};

struct list {
    node* head, * tail;
};

void init_list(list& l) {
    l.head = NULL;
    l.tail = NULL;
}

node* get_node(int x) {
    node* p = new node;
    p->val = x;
    p->next = NULL;
    return p;
}

void add_tail(list& l, int x) {
    if (l.head == NULL) l.head = l.tail = get_node(x);
    else {
        node* p = get_node(x);
        l.tail->next = p;
        l.tail = p;
    }
}

node* find(list l, int x) {
    node* p = l.head;
    while (p != NULL) {
        if (p->val == x) return p;
        p = p->next;
    }
    return NULL;
}

void insert(list*& T, int x) {
    int k = x % size;
    if (find(T[k], x) == nullptr) add_tail(T[k], x);
}


bool search(list* T, int x) {
    int k = x % size;
    return find(T[k], x) != nullptr;
}

int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    list* T = new list[size];
    for (int i = 0; i < size; i++) init_list(T[i]);



    int x, ms, i = 1;
    do {
        cin >> x;
        if (x == 0) break;
        cin >> ms;
        if (x == 1) insert(T, ms);
        else if (x == 2) cout << search(T, ms) << "\n";

        // cerr << " debug " << i++ << " " << x << " " << ms << endl;
    } while (x > 0);
}
