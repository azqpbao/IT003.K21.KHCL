
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     ios_base::sync_with_stdio(false)


int NamNhuan(int y) {
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) return 1;
	return 0;
}
struct date {
	int d, m, y;
};
void input(date* a, int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i].d >> a[i].m >> a[i].y;
	}
}
void output(date* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i].d << " " << a[i].m << " " << a[i].y << "\n";
	}
}
double tong(date a) {
	double s = 0;
	for (int i = 0; i < a.y; i++) {
		if (NamNhuan(i == 1)) s += 366;
		else s += 365;
	}
	for (int i = 0; i < a.m; i++) {
		s += 30;
	}
	s += a.d;
	return s;
}
void swap(date& a, date& b) {
	date t = a; a = b; b = t;
}
void pivot(date &a, date b) {
	a.d = b.d;
	a.m = b.m;
	a.y = b.y;
}
int compare(date a, date b) {
	if (a.y > b.y) return 1;
	if (a.y == b.y && a.m > b.m) return 1;
	if (a.y == b.y && a.m == b.m && a.d > b.d) return 1;
	return 0;
}
int partition(date* a, int l, int r) {
	date pi;
	pivot(pi, a[r]);
	int partition = l;
	for (int i = l; i < r; i++) {
		if (compare(pi, a[i]) == 1) {
			swap(a[i], a[partition]);
			partition += 1;
		}
	}
	swap(a[r], a[partition]);
	return partition;
}

void quick_sort(date* a, int l, int r) {
	if (l <= r) {
		int i = partition(a, l, r);
		quick_sort(a, l, i - 1);
		quick_sort(a, i + 1, r);
	}
}
int main() {
	int n;
	cin >> n;
	date* a = new date[n];
	input(a, n);
	quick_sort(a, 0, n - 1);
	output(a, n);
	return 0;
}