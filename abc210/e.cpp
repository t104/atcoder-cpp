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
using P = pair<ll,ll>;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<P> edges(m);
    rep(i,m) cin >> edges[i].second >> edges[i].first;
    sort(edges.begin(), edges.end());
    ll g = gcd(n, edges[0].second);
    ll ans = edges[0].first * (n-g);
    for (int i = 1; i < m; ++i) {
        auto [c,a] = edges[i];
        ll next = gcd(g, a);
        ans += c * (g-next);
        g = next;
    }
    if (g != 1) ans = -1;
    cout << ans << endl;
    return 0;
}