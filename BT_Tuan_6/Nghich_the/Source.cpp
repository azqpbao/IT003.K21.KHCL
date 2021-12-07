#include <iostream>
using namespace std;
struct arr {
	int* a;
	int n;
};
void init_arr(arr& a)
{
	a.a = NULL;
	a.n = 0;
}
void _1(arr& a, int x) {
	if (a.n == 0) {
		a.a = new int[1];
		a.a[0] = x;
		a.n += 1;
	}
	else {
		int* b = new int[a.n + 1];
		for (int i = 0; i < a.n; i++) {
			b[i] = a.a[i];
		}
		b[a.n] = x;
		delete a.a;
		a.a = b;
		a.n += 1;
	}
}
void _2(arr& a, int vitri, int x) {
	a.a[vitri] = x;
}
int nghich_the(arr a) {
	int s = 0;
	for (int i = 0; i < a.n - 1; i++) {
		for (int j = i + 1; j < a.n; j++) {
			// i > j => a[i] < a[j]
			// i < j => a[i] > a[j]***
			if (a.a[i] > a.a[j]) s++;
		}
	}
	return s;
}
int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	int n, x, vitri;
	arr a; init_arr(a);
	do {
		cin >> n;
		switch (n) {
		case 1: {
			cin >> x;
			_1(a, x);
			cout << nghich_the(a) << "\n";
			break;
		}
		case 2: {
			cin >> vitri >> x;
			_2(a, vitri, x);
			cout << nghich_the(a) << "\n";
			break;
		}
		}
	} while (n != 0);
	return 0;
}