
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::pair;

void swap(int& a, int& b) {
    int t = a; a = b; b = t;
}


int partition(int pivot, int* a, int n) {
    pivot = a[n - 1];
    int i = -1;
    for (int j = 0; j < n - 1; j ++ ) {
        if (a[j] < pivot) {
            i += 1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[n - 1]);
    return i + 1;
}

int main()
{
    int n, pivot;
    cin >> n;
    int* a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int p = partition(pivot, a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << p;
}
