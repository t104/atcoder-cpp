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
using P = pair<int,int>;

tuple<ll, ll, ll> extgcd(ll a, ll b) {
    if (b == 0) return {a, 1, 0};
    ll g, x, y;
    
    tie(g,x,y) = extgcd(b, a%b);
    return {g, y, x-a/b*y};
}

void solve() {
    ll n, s, k;
    cin >> n >> s >> k;
    ll g, x, y;
    tie(g, x, y) = extgcd(k, n);
    if (s%g != 0) {
        cout << -1 << endl;
        return;
    }
    n /= g;
    s /= g;
    k /= g;
    ll ans = ((x*-s)%n+n)%n;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i,t) solve();
    return 0;
}