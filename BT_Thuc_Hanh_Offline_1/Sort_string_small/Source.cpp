#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     ios_base::sync_with_stdio(false)


int compare(char* a, char* b) {
	for (int i = 0; i < 45; i++) {
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return 0;
	}
	return 1;
}
void copy(char*& a, char* b) {
	for (int i = 0; i < 45; i++) {
		a[i] = b[i];
	}
}
void swap(char* a, char* b) {
	char* t = new char[45];
	copy(t, a);
	copy(a, b);
	copy(b, t);
	delete t;
}
int partition(char**& a, int l, int r)
{
	char* pivot = new char[45];
	copy(pivot, a[r]);
	int partition = l;
	for (int i = l; i < r; i++)
	{
		if (compare(pivot, a[i]) == 1)
		{
			swap(a[i], a[partition]);
			partition += 1;
		}
	}
	swap(a[partition], a[r]);
	delete pivot;
	return partition;
}
void quick_sort(char **a, int l, int r)
{
	if (l < r)
	{
		int i = partition(a, l, r);
		quick_sort(a, l, i - 1);
		quick_sort(a, i + 1, r);
	}

}
int main()
{
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	char** a = new char *[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = new char[45];
		cin >> a[i];

	}
	quick_sort(a, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << endl;

	}
	delete a;
	return 0;
}