#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;
// list
struct node
{
	int val; node* next;
};
struct list
{
	node* head, * tail;
};
void init_list(list& l)
{
	l.head = l.tail = NULL;
}
node* getnode(int x)
{
	node* p = new node;
	if (p == NULL) return NULL;
	else {
		p->val = x;
		p->next = NULL;
		return p;
	}
}
void add_tail(list& l, int x)
{
	node* p = getnode(x);
	if (l.head == NULL) l.head = l.tail = p;
	else {
		l.tail->next = p;
		l.tail = p;
	}
}
void nhap_list(list& l, int n)
{
	for (int i = 0; i < n; i++)
	{
		add_tail(l, i);
	}
}
node* tim_kiem(list l, int n, int k)
{
	node* p = l.head;
	int i = 0;
	while (i < k - 1) {
		p = p->next;
		i++;
	}
	return p;
}
void delete_head_list(list& l)
{
	if (l.head = NULL);
	else if (l.head = l.tail) {
		delete l.head;
		l.tail = l.head = NULL;
	}
	else {
		auto p = l.head;
		l.head = p->next;
		delete p;
	}
}
void delete_tail_list(list& l)
{
	if (l.head = NULL);
	else if (l.head = l.tail) {
		delete l.head;
		l.tail = l.head = NULL;
	}
	else {
		node* p = l.head;
		while (p->next->next != NULL) {
			p = p->next;
		}
		delete l.tail;
		p->next = NULL;
		l.tail = p;
	}
}
void delete_middle_list(list& l, int n ,int k)
{
	node* p = tim_kiem(l, n, k);
	if (k == 0) {
		delete_head_list(l);
	}
	else if (k == n) {
		delete_tail_list(l);
	}
	else {
		auto a = p->next;
		p->next = a->next;
		delete a;
	}
}
// array
struct arr
{
	int* A;
	int n;
	int capacity;
};
void init_arr(arr& a)
{
	a.A = NULL;
	a.n = a.capacity = 0;
}
void insert_tail(arr& a, int x)
{
	if (a.n == 0) {
		a.A = new int[2];
		a.A[0] = x;
		a.n = 1;
		a.capacity = 2;
	}
	else if (a.n < a.capacity) {
		a.A[a.n] = x;
		a.n++;
	}
	else {
		auto b = new int[a.capacity * 2];
		for (int i = 0; i < a.n; i++) {
			b[i] = a.A[i];
		}
		b[a.n] = x;
		delete a.A;
		a.A = b;
		a.n++;
		a.capacity *= 2;
	}
}
void nhap_arr(arr& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		insert_tail(a, i);
	}
}
void delete_middle_arr(arr& a, int k)
{
	int* b = new int(a.capacity * 2);
	for (int i = k; i < a.n; i++)
	{
		a.A[i] = a.A[i + 1];
	}
	for (int i = 0; i < a.n - 1; i++)
	{
		b[i] = a.A[i];
	}
	delete a.A;
	a.A = b;
	a.n--;
	a.capacity = a.n * 2;
}
int main()
{
	int n = 1000;
	int k = 8;
	using namespace std::chrono;
	high_resolution_clock::time_point t1, t2;
	duration<double> time_span;
	//list
	list l; init_list(l);
	nhap_list(l,n);
	t1 = high_resolution_clock::now();
	delete_middle_list(l,n,k);
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "list: " << time_span.count() << " seconds." << endl;
	//dynamic
	arr a; init_arr(a);
	nhap_arr(a, n);
	t1 = high_resolution_clock::now();
	delete_middle_arr(a,k);
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "dynamic: " << time_span.count() << " seconds." << endl;
	int c; cin >> c;
	return 0;
}