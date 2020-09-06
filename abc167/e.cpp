#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll choose(ll x, int k, int l) {
    
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    ll ans = 1;
    ans *= m;
    ans %= MOD;
    rep(i, n-1) {
        ans *= m - 1;
        ans %= MOD;
    }
    ans += m;
    ans %= MOD;
    rep(i, n-1-k) {

    }
    cout << ans << endl;
    return 0;
}