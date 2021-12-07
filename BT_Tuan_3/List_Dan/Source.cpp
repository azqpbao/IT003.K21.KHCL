#include<bits/stdc++.h>
//#include <iostream>
//#include<math.h>
//#include<istream>
//#include<vector>
using namespace std;

#define LL long long
#define LD long double

LL n, ticks;
int dem = 0;

struct toado {
    LD x, y, u, v, s, dx, dy;
    bool arrived;
};

vector<toado> A;

LD tinh_khoang_cach(toado A) {
    return (sqrt(pow((A.x - A.u), 2) + pow((A.y - A.v), 2)));
}

LD tinh_do_dai_x(LD x, LD y, LD u, LD v, LD s) {
    LD _a = abs(x - u);
    LD _b = abs(v - y);
    LD _c = sqrt(pow(_a, 2) + pow(_b, 2));
    return ((_a / _c) * s);
}

LD tinh_do_dai_y(LD x, LD y, LD u, LD v, LD s) {
    LD _a = abs(x - u);
    LD _b = abs(v - y);
    LD _c = sqrt(pow(_a, 2) + pow(_b, 2));
    return ((_b / _c) * s);
}

void process(toado& A) {
    if (tinh_khoang_cach(A) < A.s) {
        cout << "ARRIVED" << " ";
        A.arrived = true;
        dem++;
    }
    else {
        if (A.x <= A.u)
            A.x = A.x + A.dx;//
        else
            A.x = A.x - A.dx;
        if (A.y <= A.v)
            A.y = A.y + A.dy;
        else
            A.y = A.y - A.dy;
        cout << "(" << (LL)A.x << "," << (LL)A.y << ")" << " ";
    }
}
//
//void delete_pos_in_vector(vector<toado>& A, int vitri) {
//    A.erase(A.begin() + vitri);
//    return;
}

int main() {
    freopen("1.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        toado tmp;
        LD x, y, u, v, s, dx, dy;
        cin >> tmp.x >> tmp.y >> tmp.u >> tmp.v >> tmp.s;
        tmp.dx = tinh_do_dai_x(tmp.x, tmp.y, tmp.u, tmp.v, tmp.s);
        tmp.dy = tinh_do_dai_y(tmp.x, tmp.y, tmp.u, tmp.v, tmp.s);
        tmp.arrived = false;
        A.push_back(tmp);
    }
    cin >> ticks;
    for (int i = 1; i <= ticks; i++) {
        if (dem < n) {
            vector<toado> B;
            for (int j = 0; j < A.size(); j++) {
                if (A[j].arrived == false)
                    process(A[j]);
            }
            for (int j = 0; j < A.size(); j++) {
                if (A[j].arrived == false)
                    B.push_back(A[j]);
            }
            A = B;
            cout << endl;
        }
        else exit;
    }
    return 0;
}