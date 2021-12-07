#include<iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm> 
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;
//___________________________________________ARRAY LIST_________________________________
struct arr
{
	int* A;
	int capacity;
};
void init_arr(arr& a)
{
	a.A = NULL;
	a.capacity = 0;

}
// sap xep
void swap(int& a, int& b)
{
	int t = a; a = b; b = t;
}
void selection_sort_arr(arr& a)
{
	for (int i = 0; i < a.capacity; i++) {
		int m = i;
		for (int j = i + 1; j < a.capacity; j++) {
			if (a.A[j] < a.A[m])m = j;
		}
		swap(a.A[i], a.A[m]);
	}
}
void insertion_sort_arr(arr& a) {
	for (int i = 1; i < a.capacity; i++) {
		int key = a.A[i];
		int m = i - 1;
		while (m > -1 && a.A[m] > key) {
			a.A[m + 1] = a.A[m];
			m -= 1;
		}
		a.A[m + 1] = key;
	}
}
//tao so random
int rand2()
{
	int a = rand();
	int b = rand();
	return (a << 15) | b;
}
//nhap mang
void Nhap_arr(arr& a, int n, arr& b)
{
	int r;
	srand((long long)time(0));
	a.capacity = n;
	a.A = new int[a.capacity];

	b.capacity = n;

	b.A = new int[b.capacity];
	for (int i = 0; i < a.capacity; i++)
	{
		r = rand2() % 1000000000 + 1;
		a.A[i] = r;
		b.A[i] = r;
	}

}
//___________________________________________LINKED LIST_________________________________
struct node {
	int val;
	node* next;
};
struct list {
	node* head;
	node* tail;
};
void init_list(list& a) {
	a.head = a.tail = NULL;
}
node* getnode(int x) {
	node* p = new node;
	p->val = x;
	p->next = NULL;
	return p;
}
//them cuoi
void insert_tail_list(list& l, int x) {
	node* p = getnode(x);
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else {
		l.tail->next = p;
		l.tail = p;
	}
}
//nhap list
void Nhap_list(arr a, list& l)
{
	for (int i = 0; i < a.capacity; ++i)
	{
		insert_tail_list(l, a.A[i]);
	}
}
// sap xep
void swap_node(node*& a, node*& b)
{
	int t = a->val; a->val = b->val; b->val = t;
}
void selection_sort_list(list& l) {
	for (node* i = l.head; i->next != NULL; i = i->next) {
		node* m = i;
		for (node* j = i->next; j != NULL; j = j->next) {
			if (j->val < m->val) m = j;
		}
		swap_node(i, m);
	}
}
//de in ra coi list co dung khong
void output(list l)
{
	cout << endl;
	node* p = l.head;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	int n;
	cout << "Nhap so luong n: ";
	cin >> n;
	arr a, b;
	init_arr(a);
	Nhap_arr(a, n, b);

	list l;
	init_list(l);
	Nhap_list(a, l);


	using namespace std::chrono;
	high_resolution_clock::time_point t1, t2;
	duration<double> time_span;

	//___________________________________________ARRAY LIST_________________________________
/*
	t1 = high_resolution_clock::now();
	selection_sort_arr(a);
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "Selection_sort_arr: " << time_span.count() << " seconds." << endl;
*/	
	t1 = high_resolution_clock::now();
	insertion_sort_arr(b);
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "Insertion_sort_arr: " << time_span.count() << " seconds." << endl;


	//___________________________________________LINKED LIST_________________________________
	/*
	t1 = high_resolution_clock::now();
	selection_sort_list(l);
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "Selection_sort_list: " << time_span.count() << " seconds." << endl;
	*/

	return 0;
}