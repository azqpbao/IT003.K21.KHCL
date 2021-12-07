#include<iostream>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;
//
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
void insert_head(arr& a, int x)
{
	if (a.n == 0){
		a.A = new int[2];
		a.A[0] = x;
		a.n = 1; 
		a.capacity = 2;
	}
	else if (a.n < a.capacity) {
		for (int i = a.n; i >0; i--)
		{
			a.A[i] = a.A[i - 1];
		}
		a.A[0] = x;
		a.n++;
	}
	else {
		auto b = new int[a.capacity * 2];
		for (int i = a.n; i > 0; i--)
		{
			b[i] = a.A[i - 1];
		}
		b[0] = x;
		delete a.A;
		a.A = b;
		a.n++;
		a.capacity *= 2;
	}
}
//
struct node
{
	int val;
	node* next;
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
		p->val == x;
		p->next = NULL;
	}
}
void add_head(list& l, int x)
{
	node* p = getnode(x);
	if (l.head = NULL) {
		l.head = l.tail = NULL;
	}
	else {
		p->next = l.head;
		l.head = p;
	}
}
int main()
{
	int n = 10000;
	using namespace std::chrono;
	high_resolution_clock::time_point t1, t2;
	duration<double> time_span;
	//
	list l; init_list(l);
	t1 = high_resolution_clock::now();
	for (int i = 0; i <= n; i++)
	{
		add_head(l, i);
	}
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "list: " << time_span.count() << " seconds." << endl;
	//
	arr a; init_arr(a);
	t1 = high_resolution_clock::now();
	for (int i = 0; i < n; i++)
	{
		insert_head(a, i);
	}
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "dynamic: " << time_span.count() << " seconds." << endl;
	int c; cin >> c;
	return 0;
}