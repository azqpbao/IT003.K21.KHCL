#include <iostream>
using namespace std;



int bineary_search(int* a, int l, int r, int x) {
    int m = (l + r) / 2;
    if (l <= r) {
        if (a[m] == x) {
            if (a[m + 1] == x) {
                bineary_search(a, m + 1, r, x);
            }
            else return m;
        }
        else if (a[m] > x) bineary_search(a, l, m - 1, x);
        else bineary_search(a, m + 1, r, x);
    }
    else return -1;
}

int binsearch(int* a, int x, int n) {
    return bineary_search(a, 0, n - 1, x);
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

        int it = binsearch(a, x, n);

        cout << it;
        cout << endl;
    }
}
