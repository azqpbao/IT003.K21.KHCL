#include <iostream>
using namespace std;

int binsearch(int *a, int x, int n) {
   /* int m = n / 2;
    int s;
    if (n == 0){
        return -1;
    }
    if (a[m] == x){
        s = m;
    }
    else if (a[m] > x) {
        s = binsearch(a, x, m);
    }
    else {
        s = binsearch(a + m + 1, x, n - m - 1);
        if (s != -1) {
            s += m + 1;
        }
    }
    return s;*/
    int m = n / 2;
    int s;
    if (n == 0) {
        return -1;
    }
    if (a[m] == x) {
        s = m;
    }
    else if (a[m] > x) {
        s = binsearch(a, x, m);
    }
    else {
        s = binsearch(a + m + 1, x, m);
        if (s != -1) {
            s += m + 1;
        }
    }
    return s;
}


int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;

        int it = binsearch(a,x,n);

        cout << it;
        cout << endl;
    }
}
