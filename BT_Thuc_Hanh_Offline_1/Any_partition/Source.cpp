
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define fast_io     ios_base::sync_with_stdio(false)

void swap(int& a, int& b) {
    int t = a; a = b; b = t;
}
int partition(int pivot, int* a, int n) {
    int partition = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= pivot) {
            swap(a[i], a[partition]);
            partition += 1;
        }
    }
    return partition - 1;
}

int main()
{
    int n, pivot;
    cin >> n >> pivot;
    int* a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int p = partition(pivot, a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl << p;
    return 0;
}
