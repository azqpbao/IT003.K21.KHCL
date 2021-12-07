#include <iostream>
#include <map>
using namespace std;

map<int*, int> BOOK;

void cap_phat(int*& a, int size) {
	int* x = new int[size];
	BOOK[x] = size;
	a = x;
}

void giai_phong(int* a) {
	delete a;
	BOOK.erase(a);
}

void check(int* A, int na, int ca, int l, int r) {
	if (BOOK.size() > 1) cout << "WRONG";
	if (BOOK.begin()->second != ca) cout << "WRONG";
	if (na > ca || ca > 2 * na) cout << "WRONG";
	for (int i = l; i <= r; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

void array_insert(int*& A, int& na, int& capacity_a, int x)
{
	if (capacity_a > na)
	{
		A[na] = x;
		na = na + 1;
	}
	else
	{
		int* B;
		capacity_a = 2 * (na + 1) - 1;
		cap_phat(B, capacity_a);
		for (int i = 0; i < na; i++)
		{
			B[i] = A[i];
		}
		B[na] = x;
		giai_phong(A);
		A = B;
		na = na + 1;
	}
}

int main() {
	int capacity_a;
	int na;
	int* A;

	capacity_a = 0;
	na = 0;
	cap_phat(A, na);
	int x;
	while (cin >> x) {
		array_insert(A, na, capacity_a, x);
		int l, r; cin >> l >> r;
		check(A, na, capacity_a, l, r);
	}
}

