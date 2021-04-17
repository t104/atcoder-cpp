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

int a, b;
vector<ll> s, t;

ll solve(ll x) {
    ll res = LINF;
    int si = lower_bound(s.begin(), s.end(), x) - s.begin();
    int ti = lower_bound(t.begin(), t.end(), x) - t.begin();
    if (si < a && ti < b) chmin(res, max(s[si], t[ti]) - x);
    if (0 < si && 0 < ti) chmin(res, x - min(s[si-1], t[ti-1]));
    if (si < a && 0 < ti) {
        ll l = x - t[ti-1];
        ll r = s[si] - x;
        chmin(res, l + r + min(l,r));
    }
    if (0 < si && ti < b) {
        ll l = x - s[si-1];
        ll r = t[ti] - x;
        chmin(res, l + r + min(l, r));
    }
    return res;
}

int main() {
    int q;
    cin >> a >> b >> q;
    s.resize(a);
    t.resize(b);
    rep(i,a) cin >> s[i];
    rep(i,b) cin >> t[i];
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    rep(i,q) {
        ll x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}