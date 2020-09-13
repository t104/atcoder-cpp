#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) {
        int ai;
        cin >> ai;
        a.at(ai)++;
    }

    bool ok = true;
    if (n % 2 == 0) {
        rep(i,n) {
            if (i % 2 == 0 && a.at(i) != 0) ok = false;
            if (i % 2 == 1 && a.at(i) != 2) ok = false;
        }
    }
    else {
        if (a.at(0) != 1) ok = false;
        for (int i = 1; i < n; ++i) {
            if (i % 2 == 0 && a.at(i) != 2) ok = false;
            if (i % 2 == 1 && a.at(i) != 0) ok = false;
        }

    }
    ll ans = 1;
    for (int i = 0; i < n/2; ++i) {
        ans *= 2;
        ans %= MOD;
    }
    if (ok) cout << ans << endl;
    else cout << 0 << endl;
    return 0;
}