#include <iostream>

using namespace std;
/*
void swap(int& a, int& b) {
    int t = a; a = b; b = t;
}

void down_heap(int* a, int n, int i) {
    if (i >= n || n == 0) return;
    int c = 2 * i + 1;
    if (c >= n) return;
    if ((c + 1 < n) && (a[c + 1] > a[c])) {
        c += 1;
    }
    if (a[c] > a[i]) {
        swap(a[c], a[i]);
        down_heap(a, n, c);
    }
}

void creat_heap(int* a, int capacity) {
    if (capacity == 0) return;
    int i = (capacity - 1) / 2;
    if (a[i] < a[capacity]) {
        swap(a[i], a[capacity]);
        creat_heap(a, i);
    }
}


void input(int* a, int& n, int x) {
    n += 1;
    a[n - 1] = x;
    creat_heap(a, n - 1);
}

int main() {
    int n = 0;
    int* a = new int[100000];
    int m, t;
    do {
        cin >> m;
        if (m == -2);
        else if (m == -1) {
            t = a[0];
            while ((a[0] == t) && n > 0) {
                a[0] = a[n - 1];
                n -= 1;
                down_heap(a, n, 0);
            }
        }
        else if (n < 100000 && m > 0) {
            input(a, n, m);
        }
        
    } while (m != -2);
    cout << n << "\n";
    while (n != 0) {
        cout << a[0] << "\n";
        a[0] = a[n - 1];
        n -= 1;
        down_heap(a, n, 0);
    }
    return 0;
}
*/
void swap(int& a, int& b)
{
	int t = a; a = b; b = t;
}

void down_heap(int* a, int n, int i)
{
	if (n == 0) return;
	while (i < n)
	{
		int l = 2 * i + 1;
		if (l >= n) break;
		if (l + 1 < n && a[l] < a[l + 1]) l++;
		if (a[l] > a[i])
		{
			swap(a[l], a[i]);
			i = l;
		}
		else break;
	}
}

void create_heap(int* a, int n)
{
	for (int i = n / 2; i >= 0; i--)
		down_heap(a, n, i);
}

void up_heap(int* a, int i)
{
	int p = (i - 1) / 2;
	if (i > 0 && a[p] < a[i])
	{
		swap(a[p], a[i]);
		up_heap(a, p);
	}
}

void add(int* a, int& n, int t)
{
	if (n == 0)
	{
		a[0] = t;
		n++;
	}
	else
	{
		a[n] = t;
		up_heap(a, n);
		n++;
	}
}

void output(int* a, int n)
{
	while (n > 0)
	{
		cout << a[0] << endl;
		a[0] = a[n - 1];
		n--;
		down_heap(a, n, 0);
	}
}

void heap_sort(int* a, int n)
{

	for (int i = n / 2; i >= 0; i--)
		down_heap(a, n, i);
	while (n > 0)
	{
		n--;
		swap(a[0], a[n]);
		down_heap(a, n, 0);
	}
}



void remove_max(int* a, int& n)
{
	if (n <= 0) return;
	a[0] = a[n - 1];
	n--;
	down_heap(a, n, 0);
}

void remove_all(int* a, int& n)
{
	int t = a[0];
	while (n > 0 && a[0] == t)
	{
		remove_max(a, n);
	}
}

int main()
{
	cin.tie(0);
	int n = 0, t;
	int* a = new int[100000];
	do
	{
		cin >> t;
		if (t > 0 && n < 100000)add(a, n, t);
		else if (t == -1) remove_all(a, n);
		else if (t == -2)
		{
			cout << n << endl;
			output(a, n);
		}
		if (n >= 100000) break;
		/*	for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << endl;*/
	} while (t != -2);

	delete[] a;
	return 0;
}