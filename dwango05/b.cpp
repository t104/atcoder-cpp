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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n+1);
    rep(i,n) sum[i+1] += sum[i] + a[i];
    ll ans = 0;
    for (int i = 40; 0 <= i; --i) {
        int cnt = 0;
        ll x = ans + (1LL<<i);
        for (int l = 0; l < n; ++l) {
            for (int r = l+1; r < n+1; ++r) {
                ll sub = sum[r] - sum[l];
                if ((x&sub) == x) cnt++;
            }
        }
        if (k <= cnt) ans = x;
    }
    cout << ans << endl;
    return 0;
}