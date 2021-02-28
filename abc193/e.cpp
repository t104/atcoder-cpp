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

const string dame = "infinity";

void solve() {
    ll x, y, p, q;
    cin >> x >> y >> p >> q;
    ll C = (x+y)*2, D = p+q;
    ll t = LINF;
    for (ll a = x; a < x+y; ++a) {
        for (ll b = p; b < p+q; ++b) {
            auto r = crt({a,b}, {C,D});
            if (r.second == 0) continue;
            t = min(t, r.first);
        }
    }
    if (t == LINF) cout << dame << endl;
    else cout << t << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i,t) solve();
    return 0;
}