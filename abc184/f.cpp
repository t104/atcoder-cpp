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
    ll t;
    cin >> n >> t;
    vector<ll> a(n);
    for (auto &ai: a) cin >> ai;
    int m = n / 2;
    vector<ll> sum;
    rep(i, 1<<m) {
        ll s = 0;
        rep(j,m) {
            if ((i>>j)&1) s += a[j];
        }
        sum.push_back(s);
    }
    sort(sum.begin(), sum.end());
    ll ans = 0;
    rep(i, 1<<(n-m)) {
        ll s = 0;
        rep(j,(n-m)) {
            if ((i>>j)&1) s += a[m+j];
        }
        if (t < s) continue;
        auto itr = lower_bound(sum.begin(), sum.end(), t - s);
        if (itr != sum.end() && (*itr) + s <= t) chmax(ans, (*itr) + s);
        if (itr != sum.begin()) {
            itr--;
            chmax(ans, (*itr) + s);
        }
    }
    cout << ans << endl;
    return 0;
}