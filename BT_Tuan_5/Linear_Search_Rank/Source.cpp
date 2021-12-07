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
	for (int i = 0; i < a.n; i++) {
		cin >> a.A[i];
	}
}
void Linear_Search_Rank(arr a, int x) {
	int s = 0;
	int r = 0;
	for (int i = 0; i < a.n; ++i) {
		if (a.A[i] > x) s += 1;// lon
		if (a.A[i] < x) r += 1;//be
	}
	cout << r << " " << s << endl;
}
int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	arr a, b;
	input(a);
	input(b);
	for (int i = 0; i < b.n; ++i) {
		Linear_Search_Rank(a, b.A[i]);
	}
	return 0;
}