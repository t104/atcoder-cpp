#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {

    ll a;
    double b;
    b = 0.01;
    rep(i, 100000) {
        b += 0.01;
        cout << (int) 100 * b << endl;
    }
    return 0;
}