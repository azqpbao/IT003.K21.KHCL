
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     ios_base::sync_with_stdio(false)
void swap(int& a, int& b) {
	int t = a; a = b; b = t;
}

void partition_of_dutch_national_flag(int* a, int l, int r, int &m, int &n) {
	int partition = l;
	int pivot = a[r];
	while (partition <= r) {
		if (a[partition] < pivot) {
			swap(a[partition], a[l]);
			++l;
			++partition;
		}
		else if (a[partition] > pivot) {
			swap(a[partition], a[r]);
			--r;
		}
		else {
			++partition;
		}
	}
	m = l - 1;
	n = partition;
}


void quick_sort(int* a, int l, int r) {
	if (l >= r) return;
	if (l - r == 1) {
		if (a[l] < a[r]) {
			swap(a[l], a[r]);
		}
		return;
	}
	int i, j;
	partition_of_dutch_national_flag(a, l, r, i, j);
	quick_sort(a, l, i);
	quick_sort(a, j, r);

}
int main() {
	fast_io;
	int n; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	quick_sort(a, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}