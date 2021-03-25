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


ll n, k;
vector<ll> a, f;

bool ok(ll x) {
    ll ki = k;
    rep(i,n) {
        if (a[i]*f[i] <= x) continue;
        ll q = (a[i]*f[i] - x)/f[i];
        if (x%f[i]) q++;
        if (q <= ki) ki -= q;
        else return false;
    }
    return true;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    f.resize(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());
    if (ok(0)) {
        cout << 0 << endl;
        return 0;
    }
    ll l = 0, r = LINF;
    while (l+1 < r) {
        ll m = (l+r)/2;
        if (ok(m)) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}