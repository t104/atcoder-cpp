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
    int h, w;
    cin >> h >> w;

    vector<vector<int>> dp(10, vector<int>(10));
    rep(i,10) rep(j,10) cin >> dp[i][j];
    rep(k, 10) {
        rep(i, 10) {
            rep(j, 10) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i,h) {
        rep(j,w) {
            int a;
            cin >> a;
            if (0 <= a)
                ans += dp[a][1];
        }
    }
    cout << ans << endl;

    return 0;
}