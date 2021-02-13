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

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<ll> d(n);
    rep(i,n) d[i] = b[i] - a[i];
    sort(d.begin(), d.end());
    ll sum = 0;
    int ans = 0;
    for (int i = n-1; 0 <= i; --i) {
        if (d[i] <= 0) break;
        sum += d[i];
        ans++;
    }
    rep(i,n) {
        if (sum <= 0 || 0 <= d[i]) break;
        sum += d[i];
        ans++;
    }
    if (0 < sum) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}