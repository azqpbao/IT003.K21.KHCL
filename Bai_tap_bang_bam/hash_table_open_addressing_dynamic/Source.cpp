#include <iostream>
using namespace std;
#define size 1000000

//const int size = 1000000;

struct hash_table {
    int n;
    int m;
    int* T;
    bool* markup;
    int h(int ms, int i) {
        for (; i < n; i++) {
            if (T[i] == ms) return i;
        }
        return i;
    }
};
void insert(hash_table& h, int ms);
void double_size(hash_table& h);
void insert_T(int* t, int x) {
    int k = x % size;
    int i = 1;
    while (t[k] != -1) {
        //k = (k + 1) % size;
        k += i * i;
        i += 1;
    }
    t[k] = x;
}
void double_size_T(hash_table& t) {
    hash_table h;
    h.m = t.m * 2 + 1;
    h.T = new int[h.m];
    for (int i = 0; i < h.m; i++) {
        for (auto j = t.T[i]; j = NULL;) {
            auto c = j;
            insert(h, j);
            j += 1;
        }
    }
    delete t.T;
    t = h;
}
void double_size(hash_table& t) {
    hash_table h;
    h.m = t.m * 2 + 1;
    h.T = new int[h.m];
    for (int i = 0; i < h.m; i++) {
        for (auto j = t.T[i]; j = NULL;) {
            auto c = j;
            insert(h, j);
            j += 1;
        }
    }
    delete t.T;
    t = h;
}



void insert(hash_table& t, int ms) {
    if (t.n + 1 >= t.m) double_size(t);

    int i = 0;

    do {
        int vt = t.h(ms, i);
        if (t.markup[vt] && t.T[vt] == ms) return;
        else if (t.markup[vt] == false) {
            t.T[vt] = ms;
            t.markup[vt] = true;
            t.n++;
            break;
        }
        i++;
    } while (i < t.m);
    if (i == t.m) {
        double_size(t);
        insert(t, ms);
    }
}

bool find(hash_table& t, int ms) {
    int i = 0;
    do {
        int vt = t.h(ms, i);
        if (t.markup[vt] && t.T[vt] == ms) return true;
        else if (t.markup[vt] == false) return false;
    } while (i++ < size);
    return false;
}



int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    hash_table t;
    t.m = 10;
    t.markup = new bool[t.m];
    t.T = new int[t.m];


    int x, ms, i = 1;
    do {
        cin >> x;
        if (x == 0) break;
        cin >> ms;
        if (x == 1) insert(t, ms);
        else if (x == 2) cout << find(t, ms) << "\n";

    } while (x > 0);
}

