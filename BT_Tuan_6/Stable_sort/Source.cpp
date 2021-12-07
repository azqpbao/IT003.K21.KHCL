#include <iostream>
using std::cin;
using std::cout;
using std::endl;



struct People {
	int d, m, y, p;
};
void nhap(People* a, int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i].d >> a[i].m >> a[i].y >> a[i].p;
	}
}
void xuat(People* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i].d << " " << a[i].m << " " << a[i].y << " " << a[i].p << "\n";
	}
}
void swap(People& a, People& b) {
	People t = a; a = b; b = t;
}
int tong(People a) {
	int s = a.d + a.m * 30 + a.y * 365;
	return s;
}

void stable_sort(People* a, int n) {
	int i = 1;
	while (i < n) {
		int b = tong(a[i]);
		int m = i - 1;
		while (m >= 0 && tong(a[m]) > b) {
			swap(a[m], a[m + 1]);
			m -= 1;
		}
		i += 1;
	}
}
int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	People* a = new People[n];
	nhap(a, n);
	stable_sort(a, n);
	xuat(a, n);
	return 0;
}
