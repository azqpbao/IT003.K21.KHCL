#include <iostream>
using namespace std;

int heap_check(int* a, int n, int& s) {
	for (int i = 0; 2 * i + 2 < n; i++) {
		if (a[i] < a[2 * i + 1] || a[i] < a[2 * i + 2]) s += 1;
	}
	if (s != 0) return 0;
	return 1;//heap_check
}



int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int s = 0;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (heap_check(a, n, s) == 1) cout << "HEAP\n" << s;
	else cout << "NOT HEAP\n" << s;
	return 0;
}