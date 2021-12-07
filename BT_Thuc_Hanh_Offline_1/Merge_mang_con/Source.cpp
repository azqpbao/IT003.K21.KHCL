#include <iostream>
using namespace std;

void merge(int* a, int n, int* b, int m, int* c, int vitri) {
    int i = 0, j = 0, k = vitri;
    while (i < n && j < m) {
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
    while (k < vitri + m + n) {
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

}
void its_magic(int* a, int n, int k, int* temp) {
    int m = n % k;
    int x, s;
    if ((n / k) % 2 == 0) {
        x = n - m;
        s = 0;
        // so luong ghep chan thi chi can sap xep cai con du
    }
    else {
        x = n - k - m;
        s = 1;
    }
    int i = 0;
    for (; i < x; i += (2 * k)) {
        merge(a + i, k, a + i + k, k, temp, i);
    }
    if (s == 1) {
        merge(a + i, k, a + i + k, m, temp, i);
    }
    else {
        while (i < n) {
            temp[i] = a[i];
            i += 1;
        }
    }
}


int main() {
    int n, k;
    cin >> n >> k;
    int* a = new int[n];
    int* temp = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int i = 0;

    its_magic(a, n, k, temp);

    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
}


