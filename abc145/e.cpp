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

ll dp[3005][6005];

int main() {
    int n, t;
    cin >> n >> t;
    vector<P> a(n);
    rep(i,n) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    rep(i,n) {
        rep(j,6005) {
            if (j < t) {
                chmax(dp[i+1][j+a[i].first], dp[i][j] + a[i].second);
            }
            chmax(dp[i+1][j], dp[i][j]);
        }
    }
    ll ans = 0;
    rep(i,6005) chmax(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}