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
    ll p;
    cin >> n >> k >> p;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int half = n/2;
    vector<vector<ll>> sum(k+1);
    rep(i, 1<<half) {
        int c = __builtin_popcount(i);
        if (k < c) continue;
        ll s = 0;
        rep(j, half) {
            if ((i>>j)&1) s += a[j];
        }
        sum[c].push_back(s);
    }

    rep(i,k+1) {
        sort(sum[i].begin(), sum[i].end());
    }

    ll ans = 0;
    rep(i,1<<(n-half)) {
        int c = __builtin_popcount(i);
        if (k < c) continue;
        ll s = 0;
        rep(j, n-half) {
            if ((i>>j)&1) {
                s += a[half+j];
            }
        }
        if (p < s) continue;
        ll d = p - s;
        ans += lower_bound(sum[k-c].begin(), sum[k-c].end(), d+1) - sum[k-c].begin();
    }

    cout << ans << endl;

    return 0;
}