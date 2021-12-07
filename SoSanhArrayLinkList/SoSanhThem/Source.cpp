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
//nhap mang ban dau
void Input(arr& a, int soluong)
{
	a.capacity = soluong;
	a.A = new int[soluong];
	for (int i = 0; i < soluong; i++)
	{
		a.A[i] = i;
	}
}
//chen giua
void array_add_middle(arr& a, int giatri)
{
	int z = a.capacity / 2;
	int* B;
	B = new int[a.capacity + 1];

	for (int i = 0; i < z; i++)
	{
		B[i] = a.A[i];
	}
	B[z] = giatri;
	for (int i = z + 1; i < a.capacity + 1; i++)
	{
		B[i] = a.A[i - 1];
	}
	delete a.A;
	a.A = B;
	a.capacity = a.capacity + 1;
}
//chen dau 
void array_add_head(arr& a, int giatri)
{
	int* B;
	B = new int[a.capacity + 1];
	B[0] = giatri;
	for (int i = 0; i < a.capacity; i++)
	{
		B[i + 1] = a.A[i];
	}
	delete a.A;
	a.A = B;
	a.capacity = a.capacity + 1;
}
//chen cuoi
void array_add_tail(arr& a, int giatri)
{
	int* B;
	B = new int[a.capacity + 1];
	for (int i = 0; i < a.capacity; i++)
	{
		B[i] = a.A[i];
	}
	B[a.capacity] = giatri;
	delete a.A;
	a.A = B;
	a.capacity = a.capacity + 1;
}
//kt coi mang chen dung khong
void Output(arr& a)
{
	for (int i = 0; i < a.capacity; i++)
	{
		cout << a.A[i] << " ";
	}
	cout << endl;
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
//chen dau list
void add_list_head(list& l, int giatri)
{
	node* p;
	p = getnode(giatri);
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
//chen cuoi list
void add_list_tail(list& a, int giatri)
{
	node* p;
	p = getnode(giatri);
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
//chen giua list
void add_list_middle(list& l, int giatri)
{
	node* u;
	u = getnode(giatri);
	int n = l.soluong / 2;
	auto p = l.head;
	for (int i = 0; i < n; ++i)
	{
		if (i == n - 1)
		{
			auto z = p->next;
			p->next = u;
			u->next = z;
			break;
		}
		else
		{
			p = p->next;
		}
	}
	l.soluong = l.soluong + 1;

}
//kt coi list dung khong
void output(list l)
{
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
		add_list_tail(l, i);
	}
	l.soluong = soluong;

	cout << "Nhap gia tri chen vao: ";
	int giatri;
	cin >> giatri;

	high_resolution_clock::time_point t1, t2, t3, t4;
	duration<double> time_span;
	double time1 = 0, time2 = 0;

	cout << "So lan chen: ";
	int loop;
	cin >> loop;

	for (int i = 0; i < loop; i++)
	{
		
		t1 = high_resolution_clock::now();

		array_add_middle(a, giatri);

		t2 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t2 - t1);
		time1 += time_span.count();
		
		/*
		t3 = high_resolution_clock::now();

		add_list_middle(l, giatri);

		t4 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t4 - t3);
		time2 += time_span.count();
		*/
	}
	time1 = time1 / loop;
	//time2 = time2 / loop;


	std::cout << " delete array : " << time1 << " seconds." << endl;
	//std::cout << " delete list :  " << time2 << " seconds." << endl;



}