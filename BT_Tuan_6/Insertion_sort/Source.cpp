#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

void swap(int& a, int& b) {
    int t = a; a = b; b = t;
}
void insertion_sort(int* a, int n) {
    int i = 1;
    while (i < n){
        int b = a[i];
    int m = i - 1;
    while (m >= 0 && a[m] > b) {
        swap(a[m], a[m + 1]);
        m -= 1;
    }
    i += 1;
}
}
int main() {
    int n;
    cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int* b = new int[n];

    for (int i = 0; i < 1000; i++) {
        memcpy(b, a, n * sizeof(int));
        insertion_sort(b, n);
    }

    memcpy(a, b, n * sizeof(int));
    for (int i = 0; i < n; i++) std::cout << a[i] << " ";

}

