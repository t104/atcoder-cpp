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
    int n, k;
    cin >> n >> k;
    vector<ll> d(n), a(k);
    for (int i = 1; i < n; ++i) cin >> d[i];
    rep(i,k) cin >> a[i];
    rep(i,n-1) {
        d[i+1] += d[i];
    }
    ll now = 0;
    ll ans = 0;
    rep(i,k) {
        int next = now + a[i];
        ans += abs(d.at(next) - d.at(now));
        now = next;
        ans %= 100000;
    }
    cout << ans << endl;
    return 0;
}