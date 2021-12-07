
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     ios_base::sync_with_stdio(false)

void swap(int& a, int& b) {
	int t = a; a = b; b = t;
}
int paratition(int* a, int l, int r) {
	int pivot = a[r];
	int paratition = l;
	for (int i = l; i < r; i++) {
		if (a[i] <= pivot) {
			swap(a[i], a[paratition]);
			paratition += 1;
		}
	}
	swap(a[r], a[paratition]);
	return paratition;
}
void quick_sort(int* a, int l, int r) {
	if (l < r) {
		int i = paratition(a, l, r);
		quick_sort(a, l, i - 1);
		quick_sort(a, i + 1, r);
	}
}
int main() {
	int n; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quick_sort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}