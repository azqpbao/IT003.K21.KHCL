#include <iostream>
using namespace std;
struct date {
	int ngay, thang, nam;
};
void swap_int(int& a, int& b) {
	int t = a; a = b; b = t;
}
void swap(date& a, date& b) {
	swap_int(a.ngay, b.ngay);
	swap_int(a.thang, b.thang);
	swap_int(a.nam, b.nam);
}
int sum(date a) {
	return a.ngay + a.thang * 30 + a.nam * 365;
}
void down_heap(date* a, int n, int i) {
	if (i >= n || n == 0) return;
	int c = 2 * i + 1;
	if (c >= n) return;
	if (c + 1 < n && sum(a[c]) < sum(a[c + 1])) c += 1;
	if (sum(a[c]) > sum(a[i])) {
		swap(a[c], a[i]);
		down_heap(a, n, c);
	}
}
void heap_sort(date* a, int n) {
	for (int i = n / 2 - 1; i >= 0 ; i--) {
		down_heap(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		down_heap(a, i, 0);
	}
}
void input(date* a, int& n, int d, int m, int y) {
	n += 1;
	a[n - 1].ngay = d;
	a[n - 1].thang = m;
	a[n - 1].nam = y;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	date* a = new date[1000000];
	int n = 0;
	int d, y, m;
	do {
		cin >> d;
		if (d != 0) {
			cin >> m >> y;
			input(a, n, d, m, y);
		}
	} while (d != 0);
	heap_sort(a, n);
	for (int i = 0; i < n; i++) {
		if (sum(a[i]) != sum(a[i + 1])) cout << a[i].ngay << " " << a[i].thang << " " << a[i].nam << "\n";
	}
	return 0;
}