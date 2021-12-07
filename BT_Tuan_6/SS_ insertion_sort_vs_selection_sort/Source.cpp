#include <iostream>
#include <utility>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;
// selection_sort
void selection_sort(int* a, int r, int l) {
	for (int i = l; i < r-1; i++) {
		int m = i;
		for (int j = i + 1; j < r; j++) {
			if (a[j] < a[m]) m = j;
		}
		swap(a[i], a[m]);
	}
}
// insertion_sort
void insertion_sort(int* a, int r, int l) {
	for (int i = l + 1; i < r; i++) {
		int j;
		int b = a[i];
		for (j = i - 1; j > -1; j--) {
			if (a[j] < b) break;
			else {
				a[j + 1] = a[j];
			}
		}
		a[j + 1] = b;
	}
}
// xuat
void xuat(int* a) {
	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
int main(){
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int n;
	cout << "Nhap so luong : ";
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = 100000000-i;
	}
	int s, r;
	//
	using namespace std::chrono;
	high_resolution_clock::time_point t1, t2;
	duration<double> time_span;

	// selection_sort
	t1 = high_resolution_clock::now();
	if (n > 10000 ){
		s = n / 10000;
		r = n % 10000;
		int n1 = 10000;
		for (int i = 0; i < s; i++) {
			selection_sort(a, n1, n1 - 10000);
			n1 += 10000;
		}
		if (r > 0) {
			selection_sort(a, n1 - 10000, n1 - 10000 + r);
		}
	}
	else {
		selection_sort(a, n, 0);
	}
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "Seclection sort: " << time_span.count() << " seconds." << endl;

	//
	for (int i = 0; i < n; i++) {
		a[i] = 100000000 - i;
	}
	// insertion_sort
	t1 = high_resolution_clock::now();
	if (n > 10000) {
		s = n / 10000;
		r = n % 10000;
		int n1 = 10000;
		for (int i = 0; i < s; i++) {
			insertion_sort(a, n1, n1 - 10000);
			n1 += 10000;
		}
		if (r > 0) {
			insertion_sort(a, n1 - 10000, n1 - 10000 + r);
		}
	}
	else {
		insertion_sort(a, n, 0);
	}
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "Insertion sort: " << time_span.count() << " seconds." << endl;
	return 0;
}