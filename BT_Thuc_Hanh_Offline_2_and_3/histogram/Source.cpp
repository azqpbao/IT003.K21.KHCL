#include <iostream>
#include <algorithm>
using namespace std;

void down_heap(int* a, int n, int i) {
	if (i >= n || n == 0) return;
	int c = 2 * i + 1;
	if (c >= n) return;
	if (c + 1 < n && a[c] < a[c + 1]) c += 1;
	if (a[c] > a[i]) {
		swap(a[i], a[c]);
		down_heap(a, n, c);
	}
}
void up_heap(int* a, int n) {
	if (n == 0) return;
	int i = (n - 1) / 2;
	if (a[i] < a[n]) {
		swap(a[i], a[n]);
		up_heap(a, i);
	}
}
void input(int* a, int& n, int x) {
	n += 1;
	a[n - 1] = x;
	up_heap(a, n - 1);
}
void dem(int* a, int& n, int &s) {
	int t = a[0];
	while (t == a[0] && n > 0 ) {
		s += 1;
		a[0] = a[n - 1];
		n -= 1;
		down_heap(a, n, 0);
	}
}
int main() {
	int n = 0;
	int* a = new int[1000000];
	int x, t, s;
	do {
		cin >> x;
		if (x > 0 && x < 100000000) {
			input(a, n, x);
		}
	} while (x != 0);
	while (n != 0) {
		cout << a[0] << " ";
		dem(a, n, s = 0);
		cout << s << "\n";
	}
	return 0;
}