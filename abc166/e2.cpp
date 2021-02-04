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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n), dif(n);
    rep(i,n) {
        sum[i] = a[i] + i+1;
        dif[i] = i+1 - a[i];
    }
    sort(dif.begin(), dif.end());
    ll ans = 0;
    rep(i,n) {
        auto upper = upper_bound(dif.begin(), dif.end(), sum[i]);
        auto lower = lower_bound(dif.begin(), dif.end(), sum[i]);
        ans += ll (upper - lower);
    }
    cout << ans << endl;
    return 0;
}