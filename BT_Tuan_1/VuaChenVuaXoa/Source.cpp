
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

void array_del(int*& A, int& na, int capacity_a, int i)
{
	for (int j = i; j < na; j++)
	{
		A[j] = A[j + 1];
	}
	na = na - 1;
}

void array_insert(int*& A, int& na, int& capacity_a, int i, int x)
{
	if (i == na)
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
	else if (i > na)
	{
		return;
	}
	else
	{
		int* B;
		capacity_a = 2 * (na + 1) - 1;
		cap_phat(B, capacity_a);
		for (int j = 0; j < i; j++)
		{
			B[j] = A[j];
		}
		B[i] = x;
		for (int j = i + 1; j < na + 1; j++)
		{
			B[j] = A[j - 1];
		}
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

	int op, i, x;
	while (cin >> op >> i) {
		if (op == 1) {
			array_del(A, na, capacity_a, i);
		}
		else {
			cin >> x;
			array_insert(A, na, capacity_a, i, x);

		}
		int l, r; cin >> l >> r;
		check(A, na, capacity_a, l, r);
	}
}
