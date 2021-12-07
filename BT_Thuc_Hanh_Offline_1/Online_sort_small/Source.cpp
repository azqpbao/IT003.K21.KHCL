#include <iostream>
#include <cstring>

int bin_search(int x, int* a, int n) {
	int l = 0;
	int r = n - 1;
	int m;
	while (l <= r) {
		m = (l + r) / 2;
		if (a[m] == x) return m;
		else if (a[m] > x) r = m - 1;
		else  l = m + 1;
	}
	return -1;
}

void insertion_binary_search_sort(int x, int* a, int& n)
{
	if (bin_search(x, a, n) != -1);
	else {
		a[n] = x;
		int i = n - 1;
		while (i >= 0 && a[i] > x)
		{
			a[i + 1] = a[i];
			--i;
		}
		a[i + 1] = x;
		++n;
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int* a = new int[1000000];
	int x;
	int n = 0, ms;
	do {
		std::cin >> x;
		if (x == 0) break;
		std::cin >> ms;

		if (x == 1) insertion_binary_search_sort(ms, a, n);
		else if (x == 2) std::cout << bin_search(ms, a, n) + 1 << std::endl;
	} while (x > 0);
	return 0;
}