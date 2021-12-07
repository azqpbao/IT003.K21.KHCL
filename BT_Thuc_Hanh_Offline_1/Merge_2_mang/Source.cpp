#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void merge(int* a, int n, int* b, int m, int* c) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m ) {
        if (a[i] > b[j]) {
            c[k] = b[j];
            j += 1;
        }
        else {
            c[k] = a[i];
            i += 1;
        }
        k += 1;
    }
    while (k < m + n) {
        if (i < n) {
            c[k] = a[i];
            i += 1;
            k += 1;
        }
        if (j < m) {
            c[k] = b[j];
            j += 1;
            k += 1;
        }
    }
   /*if (i < n) {
        for (int l = i; l < n; l++) {
            c[k] = a[l];
            k += 1;
        }
    }
    if (j < m) {
        for (int l = j; l < m; l++) {
            c[k] = b[l];
            k += 1;
        }
    }*/
}
int main() {
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    int t; cin >> t;
    // t: test case
    while (cin >> n >> m || t > 0) {
        t--;
        int* a = new int[n], * b = new int[m], * c = new int[n + m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        merge(a, n, b, m, c);
        int nc = n + m;;
        for (int i = 0; i < nc; i++) {
            cout << c[i] << " ";
        }
        delete c;
        cout << endl;
    }
}
