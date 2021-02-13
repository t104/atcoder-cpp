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
using P = pair<ll,ll>;

int main() {
    int n;
    ll prime;
    cin >> n >> prime;
    vector<ll> a(n), b(n), c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    ll ans = 0, now = 0;
    vector<P> sum;
    rep(i,n) {
        sum.emplace_back(a[i], c[i]);
        sum.emplace_back(b[i]+1, -c[i]);
    }
    sort(sum.begin(), sum.end());
    int m = sum.size();
    rep(i,m) {
        now += sum[i].second;
        while (i < m-1 && sum[i].first == sum[i+1].first) {
            ++i;
            now += sum[i].second;
        }
        if (m-1 <= i) break;
        ll span = sum[i+1].first - sum[i].first;
        ans += min(prime, now) * span;
    }
    cout << ans << endl;
    return 0;
}