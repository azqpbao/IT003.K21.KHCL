#include <iostream>
#include <algorithm>
using namespace std;

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

void creat_heap(int *a,int capacity) {
    if (capacity == 0) return;
    int i = (capacity - 1) / 2;
    if (a[i] < a[capacity]) {
        swap(a[i], a[capacity]);
        creat_heap(a, i);
    }
}


void input(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        creat_heap(a, i);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int *a = new int[n];
    int capacity = 0;
    input(a, n);
    int x, t, k;

    for (int i = 0; i < m; i++) {
        cin >> x;
        switch (x) {
        case -1:
            if (n == 0) break;
            a[0] = a[n - 1];
            n -= 1;
            down_heap(a, n, 0);
            break;
        case -2:
            t = a[0];
            while ((a[0] == t) && n>0) {
                a[0] = a[n - 1];
                n -= 1;
                down_heap(a, n, 0);
            }
            break;
        case -3:
            cin >> k;
            a[0] = a[0] - k;
            down_heap(a, n, 0);
            break;
        case -4:
            cin >> k;
            t = a[0];
            while (a[0] == t) {
                a[0] = a[0] - k;
                down_heap(a, n, 0);
            }
            break;
        }
    }
  
    while (n != 0) {
        cout << a[0] << "\n";
        a[0] = a[n - 1];
        n -= 1;
        down_heap(a, n, 0);
    }
    return 0;
}