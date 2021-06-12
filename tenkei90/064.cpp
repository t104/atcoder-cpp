#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

int main() {
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> bit(n);
    rep(i,n) {
        ll a;
        cin >> a;
        bit.add(i, a);
        if (i+1 < n) {
            bit.add(i+1, -a);
        }
    }
    vector<ll> dp(n-1);
    ll ans = 0;
    rep(i,n-1) {
        ll a1 = bit.sum(0, i+1);
        ll a2 = bit.sum(0, i+2);
        dp[i] = abs(a1 - a2);
        ans += dp[i];
    }
    rep(i,q) {
        int l, r;
        ll v;
        cin >> l >> r >> v;
        --l, --r;
        bit.add(l, v);
        if (r+1 < n) {
            bit.add(r+1, -v);
        }
        if (0 <= l-1) {
            ans -= dp[l-1];
            dp[l-1] = abs(bit.sum(0, l) - bit.sum(0, l+1));
            ans += dp[l-1];
        }
        if (r+1 < n) {
            ans -= dp[r];
            dp[r] = abs(bit.sum(0, r+1) - bit.sum(0, r+2));
            ans += dp[r];
        }
        cout << ans << endl;
    }
    return 0;
}