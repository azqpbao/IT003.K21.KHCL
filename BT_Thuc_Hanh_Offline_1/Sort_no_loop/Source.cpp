
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int t = a; a = b; b = t;
}

void change(int* a, int l, int r, int pivot, int &paratition) {
	if (l < r) {
		if (a[l] <= pivot) {
			swap(a[l], a[paratition]);
			paratition += 1;
			change(a, l + 1, r, pivot, paratition );
		}
		else {
			change(a, l + 1, r, pivot, paratition);
		}
	}
}
int paratition(int* a, int l, int r) {
	int pivot = a[r];
	int paratition = l;
	change(a, l, r, pivot, paratition);
	swap(a[r], a[paratition]);
	return paratition;
}

void quick_sort(int* a, int l, int r) {
	if (l <= r) {
		int i = paratition(a, l, r);
		quick_sort(a, l, i - 1);
		quick_sort(a, i + 1, r);
	}
}

void input(int* a, int n, int i) {
	if (i < n) {
		cin >> a[i];
		input(a, n, i + 1);
	}
}

void output(int* a, int n, int i) {
	if (i < n) {
		cout << a[i] << " ";
		output(a, n, i + 1);
	}
}
int main() {
	int n; cin >> n;
	int* a = new int[n];
	input(a, n, 0);
	quick_sort(a, 0, n - 1);
	output(a, n, 0);
	return 0;
}