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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0, x = 0;
    vector<P> memo(n, make_pair(-1, -1));
    bool flg = true;
    for (ll i = 0; i < k; ++i) {
        ans += a[x];
        x = ans % n;
        if (flg && memo[x].first != -1) {
            ll cycle = i - memo[x].second;
            ll d = ans - memo[x].first;
            ll q = (k-i-1) / cycle;
            ans += d * q;
            i += cycle * q;
            x = ans % n;
            flg = false;
        }
        memo[x] = make_pair(ans, i);
    }
    cout << ans << endl;
    return 0;
}

