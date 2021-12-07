#include <iostream>
using namespace std;
struct arr {
	int* A;
	int n;
	int c;
};
void input(arr& a) {
	cin >> a.n;
	a.c = a.n + 1;
	a.A = new int[a.c];
	for (int i = 0; i < a.n; ++i) {
		cin >> a.A[i];
	}
}
int Binary_Search_Don_Gian(arr a, int x) {
	int l = 0;
	int r = a.n - 1;
	int m;
	while (l <= r) {
		m = (l + r) / 2;
		if (a.A[m] == x) return m;
		else if (a.A[m] > x) r = m - 1;
		else  l = m + 1;
	}
	return -1;
}
int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	arr a, b;
	input(a);
	input(b);
	for (int i = 0; i < b.n; ++i) {
		cout << Binary_Search_Don_Gian(a, b.A[i]) << "\n";
	}
	return 0;
}