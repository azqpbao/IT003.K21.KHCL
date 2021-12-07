#include <iostream>
#include <math.h>
using namespace std;
struct arr {
	int* A;
	int c;
	int n;
};
void input(arr& a) {
	cin >> a.n;
	a.c = a.n + 1;
	a.A = new int[a.c];
	for (int i = 0; i < a.n; ++i) {
		cin >> a.A[i];
	}
}
int Linear_Search(arr a, int x) {
	int gan_nhat = 0;
	int m = 200000000;
	for (int i = 0; i < a.n; ++i) {
		if (a.A[i] == x) return i;
		if (abs(a.A[i] - x) < m)
		{
			m = abs(a.A[i] - x);
			gan_nhat = i;
		}
	}

	return gan_nhat;
}
int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	arr a, b;
	input(a);
	input(b);
	for (int i = 0; i < b.n; ++i)
	{
		cout << Linear_Search(a, b.A[i]) << endl;
	}
	return 0;
}