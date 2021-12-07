#include<iostream>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;
using namespace std::chrono;
//___________________________________________ARRAY LIST_________________________________
struct arr {
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
//duyet mang theo vi tri i
int Access_array(arr a, int vitri, int soluong)
{
	if (vitri >= soluong||vitri<0)
		return -1;
	else
		return a.A[vitri];
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
//duyet list theo vi tri i
int Access_list(list l, int vitri, int soluong)
{
	{
		if (vitri == 0)
			return l.head->val;
		else
		{
			if (vitri == soluong - 1)
				return l.tail->val;
			else
			{
				auto fast_node = l.head->next;
				auto slow_node = l.head;
				while (fast_node != NULL && fast_node->next != NULL && fast_node->next->next != NULL)
				{
					slow_node = slow_node->next;
					fast_node = fast_node->next->next;
				}
				return slow_node->next->val;
			}
		}
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

int main()
{
	cout << "Nhap so luong phan tu ban dau: ";
	int soluong;
	cin >> soluong;

	cout << "Nhap vi tri i can tim kiem: ";
	int vitri;
	cin >> vitri;
	//___________________________________________ARRAY LIST_________________________________
	arr a;
	init_arr(a);
	Input(a, soluong);
	//___________________________________________LINKED LIST_________________________________
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

	cout << "so lan tim kiem: ";
	int loop;
	cin >> loop;
	for (int i = 0; i < loop; i++)
	{
		
		t1 = high_resolution_clock::now();
		cout << Access_array(a, vitri, soluong) << "\n";

		t2 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t2 - t1);
		time1 += time_span.count();
		
		t3 = high_resolution_clock::now();
		cout << Access_list(l, vitri, soluong) << "\n";

		t4 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t4 - t3);
		time2 += time_span.count();
		
	}
	time1 = time1 / loop;
	time2 = time2 / loop;


	std::cout << " array : " << time1 << " seconds." << endl;
	std::cout << " list :  " << time2 << " seconds." << endl;



}