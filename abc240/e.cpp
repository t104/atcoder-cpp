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

ll solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<ll> z(n+1);
    rep(i,n) z[i+1] = x[i] * y[i];
    rep(i,n) z[i+1] += z[i];
    auto it = max_element(z.begin(), z.end());
    ll xi = *it;
    ll ans = 0;
    int idx = it - z.begin();
    while (0 < xi) {
        ans += xi;
        xi -= x[idx-1];
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

