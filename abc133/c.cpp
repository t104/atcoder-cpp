#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int l, r;
    cin >> l >> r;
    const int MOD = 2019;
    if (MOD <= r-l+1) {
        cout << 0 << endl;
        return 0;
    }

    l %= MOD;
    r %= MOD;

    if (r < l) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1e9;
    for (int i = l; i <= r-1; ++i) {
        for (int j = l+1; j <= r; ++j) {
            int p = (i * j) % MOD;
            ans = min(ans, p);
        }
    }
    cout << ans << endl;
    return 0;
}