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

int dp[310][310];

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,310) rep(j,310) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,n) {
        for (int j = 300; 0 <= j; --j) {
            for (int k = 300; 0 <= k; --k) {
                if (dp[j][k] == INF) continue;
                int tako = min(j + a[i], 300);
                int tai = min(k + b[i], 300);
                chmin(dp[tako][tai], dp[j][k] + 1);
            }
        }
    }
    int ans = INF;
    for (int i = x; i < 310; i++) {
        for (int j = y; j < 310; j++) {
            chmin(ans, dp[i][j]);
        }
    }
    if (INF <= ans) ans = -1;
    cout << ans << endl;
    return 0;
}

