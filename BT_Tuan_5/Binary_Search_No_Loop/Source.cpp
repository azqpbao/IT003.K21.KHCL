#include <iostream>
using namespace std;

int binary_sreach_no_loop(int* a, int x, int r, int l) {
	if (l > r) return -1;
	else {
		int m = (l + r) / 2;
		if (a[m] == x) return m;
		else if (a[m] > x) return binary_sreach_no_loop(a, x, m - 1, l);
		else binary_sreach_no_loop(a, x, r, m + 1);
	}
}
int binsearch(int *a, int x, int n) {
	return binary_sreach_no_loop(a, x, n - 1, 0);
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;

		int it = binsearch(a, x, n);

		cout << it;
		cout << endl;
	}
}
