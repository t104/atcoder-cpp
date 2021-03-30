#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<62)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    ll ans = LINF;
    rep(xi,n) rep(xj,n) rep(yi,n) rep(yj,n) {
        int cnt = 0;
        ll l = x[xi];
        ll r = x[xj];
        ll d = y[yi];
        ll u = y[yj];
        rep(i,n) {
            if (l <= x[i] && x[i] <= r && d <= y[i] && y[i] <= u) cnt++;
        }
        if (k <= cnt) chmin(ans, (r-l)*(u-d));
    }
    cout << ans << endl;
    return 0;
}