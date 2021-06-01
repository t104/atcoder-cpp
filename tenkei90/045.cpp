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
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<vector<ll>> dist(n, vector<ll>(n));
    rep(i,n) rep(j,n) {
        ll dx = x[i] - x[j];
        ll dy = y[i] - y[j];
        dist[i][j] = dx*dx + dy*dy;
    }
    vector<ll> d(1<<n);
    for (int s = 0; s < (1<<n); ++s) {
        rep(i,n) rep(j,n) {
            if ((s>>i)&1 && (s>>j)&1) chmax(d[s], dist[i][j]);
        }
    }

    vector dp(k+1, vector<ll>(1<<n, LINF));
    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
        for (int s = 0; s < (1<<n); ++s) {
            int x = 0;
            for (int j = s; j != 0; j = (j-1) & s) {
                chmin(dp[i][s], max(dp[i-1][s-j], d[j]));
                x++;
            }
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << dp[k][(1<<n)-1] << endl;
    return 0;
}