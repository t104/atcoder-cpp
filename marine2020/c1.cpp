#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n = 1;
    rep(i, 100) {
        n *= 2;
        cout << i+1 << ' ' << n << endl;
    }
    return 0;
}