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
    int n, m;
    cin >> n >> m;
    ll x, y;
    cin >> x >> y;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    ll t = 0;
    int ans = 0;
    while (true) {
        auto from_a = lower_bound(a.begin(), a.end(), t);
        if (from_a == a.end()) break;
        t = *from_a;
        t += x;
        auto from_b = lower_bound(b.begin(), b.end(), t);
        if (from_b == b.end()) break;
        ans++;
        t = *from_b;
        t += y;
    }
    cout << ans << endl;
    return 0;
}

