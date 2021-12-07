#include <iostream>

using namespace std;
int lower_bound(int* a, int x, int n) {
	int l = 0;
	int r = n - 1;
	int m;
	int s = -1;
	while (l <= r) {
		m = (l + r) / 2;
		if (a[m] == x) {
			if (l <= r) {
				s = m;
				l = m + 1;
			}
			else s = m;
		}
		else if (a[m] > x) r = m - 1;
		else l = m + 1;
	}
	return s;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	int* b = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < m; i++) {
		cout << lower_bound(a, b[i], n) << "\n";
	}
	return 0;
}
