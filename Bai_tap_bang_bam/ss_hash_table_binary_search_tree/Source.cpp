#include<iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm> 
#include <cstdlib>
#include <string>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;

// random
int rand2()
{
    int a = rand();
    int b = rand();
    return (a << 15) | b;
}
void input(int* a, int n)
{
    int r;
    srand((long long)time(0));
    for (int i = 0; i < n; i++)
    {
        r = rand2() % 1000000000 + 1;
        a[i] = r;
    }
}
// chaining 
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

void insert_chaining(list*& T, int x, int n) {
    int k = x % n;
    if (find(T[k], x) == nullptr) add_tail(T[k], x);
}
bool search_chaining(list* T, int x, int n) {
    int k = x % n;
    return find(T[k], x) != nullptr;
}


// opene addressing
/*
void insert_open_addressing(int* t, int x, int n) {
    int k = x % n;
    int i = 1;
    for (int i = 1; i < n; i++) {
        if (t[k] == -300) break;
        k += i * i;
    }
    t[k] = x;
}
int search_open_addressing(int* a, int x, int n) {
    int i = 1;
    int k = x % n;
    int f = k;
    while (a[k] != -300) {
        if (a[k] == x) {
            return 1;
        }
        k += i * i;
        i += 1;
        if (k == f && a[k] != x) {
            return 0;
        }
    }
    return 0;
}
*/

//tree
struct node_tree {
    int val;
    node_tree* left, * right;
};
node_tree* get_node_tree(int x)
{
    node_tree* t = new node_tree;
    t->val = x;
    t->left = t->right = NULL;
    return t;
}
void add_node_tree(node_tree*& root, int x)
{
    if (root == NULL) root = get_node_tree(x);
    else if (x < root->val) add_node_tree(root->left, x);
    else if (x > root->val) add_node_tree(root->right, x);
}
int search_tree(node_tree* root, int x)
{
    if (root != NULL)
    {
        if (root->val == x) return 1;
        else if (x < root->val) return search_tree(root->left, x);
        else if (x > root->val) return search_tree(root->right, x);
    }
    return 0;
}


int main() {

    //int n, x;
    //cout << "Nhap so luong phan tu: "; cin >> n;
    const int n = 1000;
    //cout << "Nhap vi tri cua gia tri a[x] can tim: ( luu y x nam trong khoang tu 0 den " << n - 1 << " ) "; cin >> x;
    int x;
    cout << "Nhap gia tri can tim: "; cin >> x;
    int* a = new int[n];
    input(a, n);

    using namespace std::chrono;
    high_resolution_clock::time_point t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
    duration<double> time_span;
    double time1 = 0, time2 = 0, time3 = 0, time4 = 0, time5 = 0, time6 = 0;

   

    // chaining
    list* T = new list[n];
    for (int i = 0; i < n; i++) init_list(T[i]);

    // open addressing
    int* t = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        t[i] = -300;
    }

    //tree
    node_tree* root = NULL;


    t1 = high_resolution_clock::now();

    //         insert
    for (int i = 0; i < n; i++) {
        insert_chaining(T, a[i], n);
    }

    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    time1 += time_span.count();

    t3 = high_resolution_clock::now();

    //         insert
    for (int i = 0; i < n; i++) {
       // insert_open_addressing(t, a[i], n);
    }

    t4 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t4 - t3);
    time2 += time_span.count();

    t5 = high_resolution_clock::now();

    //         insert
    for (int i = 0; i < n; i++) {
        add_node_tree(root, a[i]);
    }

    t6 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t6 - t5);
    time3 += time_span.count();

    t7 = high_resolution_clock::now();

    //         search
    search_chaining(T, x, n);

    t8 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t8 - t7);
    time4 += time_span.count();

    t9 = high_resolution_clock::now();

    //         search
    //search_open_addressing(t, x, n);

    t10 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t10 - t9);
    time5 += time_span.count();

    t11 = high_resolution_clock::now();

    //         search
    search_tree(root, x);

    t12 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t12 - t11);
    time6 += time_span.count();



    cout << "Insert_chaining : " << time1 << " seconds." << "\n";
    cout << "Search_chaining : " << time4 << " seconds." << "\n\n";

    cout << "Insert_open_addresing : " << time2 << " seconds." << "\n";
    cout << "Search_open_addresing : " << time5 << " seconds." << "\n\n";

    cout << "Insert_tree : " << time3 << " seconds." << endl;
    cout << "Search_tree : " << time6 << " seconds." << "\n\n";


    return 0;
}
/*
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int n, x;
    cout << "Nhap so luog phan tu : "; cin >> n;
    cout << "Nhap vi tri cua gia tri a[x] can tim: ( luu y x nam trong khoang tu 0 den "<<n-300<< " ) "; cin >> x;
    int* a = new int[n];
    input(a, n);
    using namespace std::chrono;
    high_resolution_clock::time_point t1, t2, t3, t4, t5, t6, t7, t8;
    duration<double> time_span;
    double time1 = 0, time2 = 0, time3 = 0, time4 = 0;
    // chaining
    list* T = new list[n];
    for (int i = 0; i < n; i++) init_list(T[i]);
    //         insert
    for (int i = 0; i < n; i++) {
        insert_chaining(T, a[i], n);
    }
    //         search
    search_chaining(T, a[x], n);
 
    // open addressing
    int* t = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        t[i] = -300;
    }
    //         insert
    for (int i = 0; i < n; i++) {
        insert_open_addressing(t, a[i], n);
    }
    //         search
    search_open_addressing(t, a[x], n);

    //tree
    node_tree* root = NULL;
     //         insert
    for (int i = 0; i < n; i++) {
        add_node_tree(root, a[i]);
    }
    //         search
    search_tree(root, a[x]);
    return 0;
}

*/

