#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;
struct arr
{
	int* A;
	int n;
	int capacity;
};
void init_array(arr& a)
{
	a.A = NULL;
	a.capacity = a.n = 0;
}
void insert_tail(arr& a, int x)
{
	if (a.n == 0) {
		a.A = new int[2];
		a.A[0] = x;
		a.n = 1;
		a.capacity = 2;
	}
	else if (a.n < a.capacity) {
		a.A[a.n] = x;
		a.n++;
	}
	else {
		auto b = new int[a.capacity * 2];
		for (int i = 0; i < a.n; i++) {
			b[i] = a.A[i];
		}
		b[a.n] = x;
		delete a.A;
		a.A = b;
		a.n++;
		a.capacity *= 2;
	}
}
int Linear_Search_if_trong_vong_lap(arr a, int x) {
	for (int i = 0; i < a.n; i++) {
		if (a.A[i] == x) return i;
	}
	return -1;
}
int Linear_Search_if_ngoai_vong_lap(arr a, int x) {
	int i = 0;
	/*insert_tail(a, x);*/
	a.A[a.n] = x;
	while (a.A[i] != x) i++;
	if (i < a.n) return i;
	return -1;
}
int main() {
	int n = 100000000;
	int x = 85357;
	arr a; init_array(a);
	for (int i = 0; i < n; i++) {
		insert_tail(a, i);
	}
	using namespace std::chrono;
	high_resolution_clock::time_point t1, t2;
	duration<double> time_span;
	//If trong vong lap

	t1 = high_resolution_clock::now();
	cout << Linear_Search_if_trong_vong_lap(a, x) << endl;
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "If trong vong lap: " << time_span.count() << " seconds." << endl;
	//If ngoai vong lap

	t1 = high_resolution_clock::now();
	cout << Linear_Search_if_ngoai_vong_lap(a, x) << endl;
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "If ngoai vong lap: " << time_span.count() << " seconds." << endl;
	int c; cin >> c;
	return 0;

}