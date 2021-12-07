#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Date {
	int d, m, y;
};
void nhap(Date* a, int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i].d >> a[i].m >> a[i].y;
	}
}
void xuat(Date* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i].d << " " << a[i].m << " " << a[i].y << "\n";
	}
}
void swap(Date& a, Date& b) {
	Date t = a; a = b; b = t;
}

void sort_date(Date* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int m = i;
		for (int j = i + 1; j < n; j++) {
			if (a[i].y > a[j].y) {
				swap(a[i], a[j]);
			}
			else if (a[i].m > a[j].m && a[i].y ==a[j].y) {
				swap(a[i], a[j]);
			}
			else if (a[i].d > a[j].d && a[i].m == a[j].m && a[i].y == a[j].y) {
				swap(a[i], a[j]);
			}
		}
	}
}
int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	Date* a = new Date[n];
	nhap(a, n);
	sort_date(a, n);
	xuat(a, n);
	return 0;
}