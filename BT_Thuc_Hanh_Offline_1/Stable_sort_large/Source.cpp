
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     ios_base::sync_with_stdio(false)



struct People {
    int d, m, y, p;
    long int s;
};

long int sum(People a) {
    return a.d + a.m * 30 + a.y * 365;
}
void input(People* a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i].d >> a[i].m >> a[i].y >> a[i].p;
        a[i].s = sum(a[i]);
    }
}
void output(People* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i].d << " " << a[i].m << " " << a[i].y << " " << a[i].p << "\n";
    }
}
void merge(People* a, int n, People* b, int m, People* c, int vitri) {
    int i = 0, j = 0, k = vitri;
    while (i < n && j < m) {
        if (a[i].s <= b[j].s) {
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
    if (i < n) {
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
    }
}
void its_magic(People* a, int n, int k, People* temp)
{
    int i = 0;
   for ( ; i + 2 * k <= n; i += 2 * k)
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
void stable_sort(People* a, int n) {
    People* temp = new People[n];
    for (int i = 1; i < n; i *= 2) {
        its_magic(a, n, i, temp);
        for (int j = 0; j < n; j++)
            a[j] = temp[j];
    }
    delete temp;
}

int main() {
    cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    People* a = new People[n];
    input(a, n);
    stable_sort(a, n);
    output(a, n);
    return 0;
}

