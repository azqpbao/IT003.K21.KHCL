#include<iostream>
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
// tim kiem
int lineary_search_normal_arr(arr a, int x)
{
	int i = 0;
	while (i < a.capacity)
	{
		if (a.A[i] == x)
		{
			return i;
		}
		i++;
	}
	return -1;
}
int lineary_search_updated_arr(arr a, int x)
{
	a.A[a.capacity] = x;
	int i = 0;
	while (a.A[i] != x) i++;
	if (i < a.capacity) return i;
	else
		return -1;
}
int bineary_search_arr(arr a, int x)
{
	int l = 0;
	int r = a.capacity - 1;
	int m;
	while (l <= r)
	{
		m = (r + l) / 2;
		if (a.A[m] == x) return m;
		else if (a.A[m] > x) r = m - 1;
		else l = m + 1;
	}
	return -1;
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
//xoa cuoi
void delete_node_tail(list& l)
{
	for (auto p = l.head; p != NULL; p = p->next)
	{
		if (p->next == l.tail)
		{
			auto u = l.tail;
			p->next = NULL;
			delete u;
			l.tail = p;
		}
	}

}
// tim kiem
int lineary_search_normal_list(list l, int x)
{
	int j = 0;
	node* p = l.head;
	while (p != NULL)
	{
		if (p->val == x)
		{
			return j;
		}
		j++;
		p = p->next;
	}
	return -1;
}
int lineary_search_updated_list(list& l, int x, int n)
{
	insert_tail_list(l, x);
	int i = 0;
	node* p = l.head;
	while (p->val != x)
	{
		i++;
		p = p->next;
	}
	if (i < n) return i;
	return -1;
}
void output(list l)
{
	node* p = l.head;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
}
int main()
{

	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;

	arr a;
	init_arr(a);
	a.A = new int[n];
	a.capacity = n;
	//nhap mang
	for (int i = 0; i < n; i++)
	{
		a.A[i] = i;
	}

	list l;
	init_list(l);
	//nhap list
	for (int i = 0; i < n; i++)
	{
		insert_tail_list(l, i);
	}

	int x;
	cout << "Nhap gia tri x can tim kiem: ";
	cin >> x;
	//
	using namespace std::chrono;
	high_resolution_clock::time_point t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
	duration<double> time_span;
	double time1 = 0, time2 = 0, time3 = 0, time4 = 0, time5 = 0;
	// so sanh
	//___________________________________________ARRAY LIST_________________________________
	//tim kiem

	cout << "So lan tim kiem: ";
	int loop;
	cin >> loop;

	for (int i = 0; i < loop; ++i)
	{
		
		t1 = high_resolution_clock::now();
		lineary_search_normal_arr(a, x);
		t2 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t2 - t1);
		time1 += time_span.count();

		
		
		t3 = high_resolution_clock::now();
		lineary_search_updated_arr(a, x);
		t4 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t4 - t3);
		time2 += time_span.count();
		
		
		t5 = high_resolution_clock::now();
		bineary_search_arr(a, x);
		t6 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t6 - t5);
		time3 += time_span.count();
		
		//___________________________________________LINKED LIST_________________________________
		//tim kiem
		
		t7 = high_resolution_clock::now();
		lineary_search_normal_list(l, x);
		t8 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t8 - t7);
		time4 += time_span.count();
		
		
		t9 = high_resolution_clock::now();
		lineary_search_updated_list(l, x, n);
		t10 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t10 - t9);
		time5 += time_span.count();
		
		delete_node_tail(l);
		

	}
	
	time1 = time1 / loop;
	time2 = time2 / loop;
	time3 = time3 / loop;
	time4 = time4 / loop;
	
	time5 = time5 / loop;


	
	cout << "Lineary_search_normal_arr: " << time1 << " seconds." << endl;
	cout << "Lineary_search_updated_arr: " << time2 << " seconds." << endl;
	cout << "Bineary_search_arr: " << time3 << " seconds." << endl;
	
	cout << "Lineary_search_normal_list: " << time4 << " seconds." << endl;
	
	cout << "Lineary_search_updated_list: " << time5 << " seconds." << endl;

	return 0;
}