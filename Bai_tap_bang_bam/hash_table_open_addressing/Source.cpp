#include <iostream>
using namespace std;
#define EMPTY -1
#define size 1000000

const int EMPTY = -1;
const int size = 1000000;

void insert(int* t, int x) {
    int k = x % size;
    int i = 1;
    while (t[k] != -1) {
        //k = (k + 1) % size;
        k += i * i;
        i += 1;
    }
    t[k] = x;
}
int find(int* t, int x) {
    int k = x % size;
    int i = 1;
    while (t[k] != -1) {
        if (t[k] == x) return 1;
       // k = (k + 1) % size;
        k += i * i;
        i += 1;
    }
    return 0;
}

int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int* t = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        t[i] = EMPTY;
    }

    int x, ms, i = 1;
    do {
        cin >> x;
        if (x == 0) break;
        cin >> ms;
        if (x == 1) insert(t, ms);
        else if (x == 2) cout << find(t, ms) << "\n";

        // cerr << " debug " << i++ << " " << x << " " << ms << endl;
    } while (x > 0);
}
