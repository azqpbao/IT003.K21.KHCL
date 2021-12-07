#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int t = a; a = b; b = t;
}

void down_heap(int* a, int n, int i) {
    if (i >= n || n == 0) return;
    int c = 2 * i + 1;
    if (c >= n) return;
    if ((c + 1 < n) && (a[c + 1] > a[c])) {
        c += 1;
    }
    if (a[c] > a[i]) {
        swap(a[c], a[i]);
        down_heap(a, n, c);
    }

}

void heap_sort(int* a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        down_heap(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(a[i], a[0]);
        down_heap(a, i, 0);
    }
}
void input(int* a, int& n, int x) {
    n += 1;
    a[n - 1] = x;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int* a = new int[1000000];
    int n = 0;
    int x;
    do {
        cin >> x;
        if (x != 0) {
            input(a, n, x);
        }
    } while (x != 0);
    heap_sort(a, n);
    for (int i = 0; i < n ; i++) {
        if (a[i] == a[i + 1]);
        else cout << a[i] << "\n";
    }
    return 0;
}