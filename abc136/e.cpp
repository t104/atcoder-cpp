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
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 1;
    auto ok = [&](ll x) {
        ll cnt = 0;
        ll rs = 0;
        vector<ll> r(n);
        rep(i,n) {
            r[i] = a[i] % x;
            rs += r[i];
        }
        sort(r.rbegin(), r.rend());
        rep(i, rs / x) {
            cnt += x - r[i];
        }
        return cnt <= k;
    };
    for (ll i = 1; i * i <= sum; ++i) {
        if (sum % i) continue;
        ll cnt = 0;
        if (ok(i)) chmax(ans, i);
        if (sum / i != i && ok(sum / i)) chmax(ans, sum / i);
    }
    cout << ans << endl;
    return 0;
}