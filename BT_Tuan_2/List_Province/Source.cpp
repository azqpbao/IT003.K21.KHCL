#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct province
{
	int id;
	string name;
	long int pop;
	double area;
};
void nhap(province &a)
{
	do
	{
		cin >> a.id;
	} while (a.id <= 0 || a.id >= 100);
	cin.ignore();
	getline(cin, a.name);
	do
	{
		cin >> a.pop;
	} while (a.pop <= 0 || a.id >= 10000);
	do
	{
		cin >> a.area;
	} while (a.area <= 0 || a.area >= 20000);
 }

void xuat(province a)
{
	cout << a.id << "\t" << a.name << "\t" << a.pop << "\t" << a.area << endl;
}

struct node
{
	province val;
	node* next;
};

struct List
{
	node* head, * tail;
};

void Init(List& l)
{
	l.head = l.tail = NULL;
}

node* getnode(province a)
{
	node* p = new node;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->val = a;
		p->next = NULL;
		return p;
	}
}

void add_tail(List& l, province x)
{
	node* p;
	p= getnode(x);
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void inputListProvinces(List& l)
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		province x; nhap(x);
		add_tail(l, x);
	}
}

void outputListProvinces(List l)
{
	node* p = l.head;
	while (p != NULL)
	{
		xuat(p->val);
		p = p->next;
	}
}

void outputProvincesMore1MillionPop(List& l)
{
	for (node* p = l.head; p != NULL; p = p->next)
	{
		if (p->val.pop > 1000)
		{
			xuat(p->val);
		}
	}
}

node* findProMaxArea(List &l)
{
	node* ln = l.head;
	for (node* p = l.head->next; p != NULL; p = p->next)
	{
		if (p->val.area > ln->val.area)
		{
			ln = p;
		}
	}
	return ln;
}

void outputProvince(node* p)
{
	xuat(p->val);
}
int main()
{
	List L;
	Init(L);
	inputListProvinces(L);
	cout << "List of provinces:" << endl;
	cout << "ID\t|Province\t|Population\t|Area" << endl;
	outputListProvinces(L);

	cout << "Provinces with a population of more than 1 million:" << endl;
	outputProvincesMore1MillionPop(L);

	cout << "The largest province:" << endl;
	node* p = findProMaxArea(L);
	if (p) outputProvince(p);

	return 0;
}



