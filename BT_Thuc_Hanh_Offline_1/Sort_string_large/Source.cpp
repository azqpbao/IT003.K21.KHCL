#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     ios_base::sync_with_stdio(false)
char t;
int compare(char* a, char* b) {
	for (int i = 0; i < 7; i++) {
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return 0;
	}
	return 1;
}
void swap(char* a, char* b) {
	for (int i = 0; i < 30; i++) {
		t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
}
int partition(char**& a, int l, int r)
{
	char* pivot = new char[7];
	for (int i = 0; i < 7; i++) {
		pivot[i] = a[l][i];
	}
	int i = l - 1;
	int j = r;
	while (1) {
		do {
			i += 1;
		} while (compare(pivot, a[i]) == 1);
		do {
			j -= 1;
		} while (compare(a[j], pivot) == 1);
		delete []pivot;
		if (i >= j) {
			
			return j + 1;
		}
		swap(a[i], a[j]);
	}
}
void quick_sort(char** a, int l, int r)
{
	if (l < r)
	{
		int i = partition(a, l, r);
		quick_sort(a, i + 1, r);
		quick_sort(a, l, i);
	}

}
int main()
{
	fast_io;
	int n;
	cin >> n;
	char** a = new char* [n];
	for (int i = 0; i < n; ++i) {
		a[i] = new char[30];
		cin >> a[i];

	}
	quick_sort(a, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << endl;

	}
	return 0;
}