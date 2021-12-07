#include<iostream>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;
using namespace std::chrono;
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
void Input(arr& a, int soluong)
{
	a.capacity = soluong;
	a.A = new int[soluong];
	for (int i = 0; i < soluong; i++)
	{
		a.A[i] = i;
	}
}
//xoa mang giua
void array_delete_middle(arr& a)
{
	int z = a.capacity / 2;
	int* B;
	B = new int[a.capacity - 1];
	for (int i = 0; i < z; i++)
	{
		B[i] = a.A[i];
	}
	for (int i = z; i < a.capacity; i++)
	{
		B[i] = a.A[i + 1];
	}
	delete a.A;
	a.A = B;
	a.capacity = a.capacity - 1;
}
//xoa mang dau
void array_delete_head(arr& a)
{
	int* B;
	B = new int[a.capacity - 1];

	for (int i = 0; i < a.capacity - 1; i++)
	{
		B[i] = a.A[i + 1];
	}

	delete a.A;
	a.A = B;
	a.capacity = a.capacity - 1;
}
//xoa mang cuoi
void array_delete_tail(arr& a)
{
	int* B;
	B = new int[a.capacity - 1];
	for (int i = 0; i < a.capacity - 1; i++)
	{
		B[i] = a.A[i];
	}
	delete a.A;
	a.A = B;
	a.capacity = a.capacity - 1;
}
void Output(arr& a)
{
	for (int i = 0; i < a.capacity; i++)
	{
		cout << a.A[i] << " ";
	}
}
//___________________________________________LINKED LIST_________________________________
struct node
{
	int val;
	node* next;
};
struct list
{
	int soluong;
	node* head;
	node* tail;
};
void init_list(list& a)
{
	a.head = a.tail = NULL;
}
node* getnode(int x)
{
	node* p = new node;
	p->val = x;
	p->next = NULL;
	return p;
}
//them cuoi
void add_back(list& a, int b)
{
	node* p;
	p = getnode(b);
	if (a.head == NULL)
	{
		a.head = p;
		a.tail = p;
	}
	else
	{
		a.tail->next = p;
		a.tail = p;
	}
}
//xoa node cuoi
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
//xoa node giua
void delete_node_middle(list& l)
{
	int n = l.soluong / 2;
	auto p = l.head;

	for (int i = 0; i < n; ++i)
	{
		if (i == n - 1)
		{
			auto u = p->next;
			p->next = u->next;
			delete u;
			break;

		}
		else
		{
			p = p->next;
		}
	}
	l.soluong = l.soluong - 1;
}
//xoa node dau
void delete_node_head(list& l)
{
	node* p = l.head;
	if (l.head == l.tail)
	{
		delete l.head;
		l.head = l.tail = NULL;
	}
	else
	{
		l.head = p->next;
		delete p;
	}
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
//___________________________________________MAIN_________________________________
int main()
{
	cout << "Nhap so luong phan tu ban dau: ";
	int soluong;
	cin >> soluong;

	arr a;
	init_arr(a);
	Input(a, soluong);

	list l;
	init_list(l);
	for (int i = 0; i < soluong; ++i)
	{
		add_back(l, i);
	}
	l.soluong = soluong;

	high_resolution_clock::time_point t1, t2, t3, t4;
	duration<double> time_span;
	double time1 = 0, time2 = 0;

	cout << "Nhap so lan lap: ";
	int loop;
	cin >> loop;

	for (int i = 0; i < loop; i++)
	{
		
		t1 = high_resolution_clock::now();

		array_delete_tail(a);

		t2 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t2 - t1);
		time1 += time_span.count();

		t3 = high_resolution_clock::now();

		delete_node_tail(l);

		t4 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t4 - t3);
		time2 += time_span.count();
		
	}
	 time1 = time1 / loop;
	time2 = time2 / loop;


	std::cout << " delete array : " << time1 << " seconds." << endl;
	std::cout << " delete list :  " << time2 << " seconds." << endl;



}
