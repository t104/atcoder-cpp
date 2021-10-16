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

void solve() {
    vector<ll> balls(3);
    rep(i,3) cin >> balls[i];
    sort(balls.begin(), balls.end());
    ll ans = LINF;
    vector<P> choose = {
        {0, 1},
        {1, 2},
        {0, 2}
    };
    for (auto [x, y]: choose) {
        if (balls[x] % 3 != balls[y] % 3) continue;
        chmin(ans, balls[y]);
    }
    if (ans == LINF) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}

