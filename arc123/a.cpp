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
    vector<ll> a(3);
    rep(i,3) cin >> a[i];
    if (a[2] < a[0]) swap(a[0], a[2]);
    ll ans = 0;
    ll d = a[2] - a[0];
    if (d%2 == 1) ans++, d++;
    if (a[1] < a[0] + d/2) {
        ans += a[0] + d/2 - a[1];
    } else {
        ans = max(a[2]-a[1], a[1]-a[0]) - min(a[2]-a[1], a[1]-a[0]);
    }
    cout << ans << endl;
    return 0;
}

