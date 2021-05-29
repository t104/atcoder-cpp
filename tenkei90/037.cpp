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

ll op (ll x, ll y) {
    return max(x,y);
}

ll e () {
    return -LINF;
}

vector<segtree<ll, op, e>> dp(510, segtree<ll, op, e>(10010));

int main() {
    int w, n;
    cin >> w >> n;
    vector<int> l(n), r(n);
    vector<ll> v(n);
    rep(i,n) cin >> l[i] >> r[i] >> v[i];
    
    dp[0].set(0, 0);
    rep(i,n) {
        rep(j,w+1) {
            if (dp[i+1].get(j) < dp[i].get(j)) {
                dp[i+1].set(j, dp[i].get(j));
            }
            int mi = max(0, j-r[i]);
            int mx = max(0, j-l[i]+1);
            ll x = dp[i].prod(mi, mx) + v[i];
            if (dp[i+1].get(j) < x) {
                dp[i+1].set(j, x);
            }
        }
    }

    ll ans = dp[n].get(w);
    if (ans < 0) ans = -1;
    cout << ans << endl;
    return 0;
}