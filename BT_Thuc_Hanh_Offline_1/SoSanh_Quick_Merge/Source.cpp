#include<iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm> 
#include <cstdlib>
#include <string>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;
int rand2()
{
	int a = rand();
	int b = rand();
	return (a << 15) | b;
}
//nhap mang

void input(int* a, int n, int* b, int *c, int *d)
{
	int r;
	srand((long long)time(0));
	for (int i = 0; i < n; i++)
	{
		r = rand2() % 1000000000 + 1;
		a[i] = r;
		b[i] = r;
		c[i] = r;
		d[i] = r;
	}

}

// quick sort 
//-------- paratition lomuto -------- 

int lomuto_paratition(int* a, int l, int r) {
	int pivot = a[r];
	int paratition = l - 1;
	for (int i = l; i < r; i++) {
		if (a[i] < pivot) {
			paratition += 1;
			swap(a[i], a[paratition]);
		}
	}
	swap(a[paratition + 1], a[r]);
	return paratition + 1;
}

//-------- quick sort lomuto --------
void quick_sort_lomuto(int* a, int l, int r) {
	if (l < r) {
		int i = lomuto_paratition(a, l, r);
		quick_sort_lomuto(a, l, i - 1);
		quick_sort_lomuto(a, i + 1, r);
	}
}

//-------- paratition hoares -------- 

int hoares_paratition(int* a, int l, int r) {
	int pivot = a[l];
	int i = l - 1;
	int j = r + 1;
	int partition = l;
	while (partition <= r) {
		do {
			i += 1;
		} while (a[i] < pivot);
		do {
			j -= 1;
		} while (a[j] > pivot);
		if (i >= j) {
			return j;
		}
		swap(a[i], a[j]);
	}
}

//-------- quick sort hoares --------
void quick_sort_hoares(int* a, int l, int r) {
	if (l < r) {
		int i = hoares_paratition(a, l, r);
		quick_sort_hoares(a, l, i - 1);
		quick_sort_hoares(a, i + 1, r);
	}
}

//-------- paratition of dutch national flag -------- 
void partition_of_dutch_national_flag(int* a, int l, int r, int& m, int& n) {
	int partition = l;
	int pivot = a[r];
	while (partition <= r) {
		if (a[partition] < pivot) {
			swap(a[partition], a[l]);
			++l;
			++partition;
		}
		else if (a[partition] > pivot) {
			swap(a[partition], a[r]);
			--r;
		}
		else {
			++partition;
		}
	}
	m = l - 1;
	n = partition;
}

//-------- quick sort of dutch national flag --------
void quick_sort_of_dutch_national_flag(int* a, int l, int r) {
	if (l >= r) return;
	if (l - r == 1) {
		if (a[l] < a[r]) {
			swap(a[l], a[r]);
		}
		return;
	}
	int i, j;
	partition_of_dutch_national_flag(a, l, r, i, j);
	quick_sort_of_dutch_national_flag(a, l, i);
	quick_sort_of_dutch_national_flag(a, j, r);

}

// merge sort 
//-------- merge -------- 
void merge(int* a, int n, int* b, int m, int* c, int vitri) {
	int i = 0, j = 0, k = vitri;
	while (i < n && j < m) {
		if (a[i] <= b[j]) {
			c[k] = a[i];
			i += 1;
			k += 1;
		}
		else {
			c[k] = b[j];
			j += 1;
			k += 1;
		}
	}
	while (i < n) {
		c[k] = a[i];
		i += 1;
		k += 1;
	}
	while (j < m) {
		c[k] = b[j];
		j += 1;
		k += 1;
	}
}
void its_magic(int* a, int n, int k, int* temp)
{
	int i = 0;
	for (; i + 2 * k <= n; i += 2 * k)
	{
		merge(a + i, k, a + i + k, k, temp, i);
	}
	if (i + 2 * k > n && i + k < n)
		merge(a + i, k, a + i + k, n - i - k, temp, i);
	else {
		while (i < n) {
			temp[i] = a[i];
			i += 1;
		}
	}
}

//-------- merge sort -------- 
void merge_sort(int* a, int n) {
	int* temp = new int[n];
	for (int i = 1; i < n; i *= 2) {
		its_magic(a, n, i, temp);
		memcpy(a, temp, n * sizeof(int));
	}
	delete temp;
}

// output
void output(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}
//-------- ham main --------
int main() {
	
	int n;
	cout << "Nhap so luong phan tu: "; cin >> n;

	int* a = new int[n];
	int* b = new int[n];
	int* c = new int[n];
	int* d = new int[n];
	
	using namespace std::chrono;
	high_resolution_clock::time_point t1, t2, t3, t4, t5, t6, t7, t8;
	duration<double> time_span;
	double time1 = 0, time2 = 0, time3 = 0, time4 = 0;

	cout << "Nhap so lan lap: ";
	int loop;
	cin >> loop;

	for (int i = 0; i < loop; i++)
	{
		input(a, n, b, c, d);
		t1 = high_resolution_clock::now();

		merge_sort(a, n);

		t2 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t2 - t1);
		time1 += time_span.count();

		t3 = high_resolution_clock::now();

		quick_sort_lomuto(b, 0, n - 1);

		t4 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t4 - t3);
		time2 += time_span.count();

		t5 = high_resolution_clock::now();

		quick_sort_of_dutch_national_flag(c, 0, n - 1);

		t6 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t4 - t3);
		time3 += time_span.count();

		t7 = high_resolution_clock::now();

		quick_sort_hoares(d, 0, n - 1);

		t8 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t4 - t3);
		time4 += time_span.count();
	}
	time1 = time1 / loop;
	time2 = time2 / loop;
	time3 = time3 / loop;
	time4 = time4 / loop;

	cout << "Merge_sort: " << time1 << " seconds." << endl;
	cout << "Quick_sort_lomuto: " << time2 << " seconds." << endl;
	cout << "Quick_sort_of_dutch_national_flag: " << time3 << " seconds." << endl;
	cout << "Quick_sort_hoares: " << time4 << " seconds." << endl;
	
	
	return 0;
}