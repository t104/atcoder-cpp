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

int H, W;
int A[50][50];
int dp[50][50][50][50];

P d[] = {
    make_pair(1, 1),
    make_pair(1, -1),
    make_pair(-1, 1),
    make_pair(-1, -1)
};

int main() {
    cin >> H >> W;
    rep(i,H) rep(j, W) cin >> A[i][j];
    rep(i, 50) rep(j, 50) rep(k, 50) rep(l, 50) dp[i][j][k][l] = INF;
    rep(i, H) rep(j, W) {
        dp[i][j][i][j] = A[i][j];
        for (auto &[dh, dw] : d) {
            for (int hi = i; in(hi, 0, H); hi += dh) {
                for (int wi = j; in(wi, 0, W); wi += dw) {
                    if (in(wi-dw, 0, W)) chmin(dp[i][j][hi][wi], dp[i][j][hi][wi-dw] + A[hi][wi]);
                    if (in(hi-dh, 0, H)) chmin(dp[i][j][hi][wi], dp[i][j][hi-dh][wi] + A[hi][wi]);
                }
            }
        }
    }
    int ans = INF;
    rep(i,H) rep(j,W) {
        chmin(ans, dp[i][j][H-1][0] + dp[i][j][H-1][W-1] + dp[i][j][0][W-1] - 2 * A[i][j]);
    }
    cout << ans << endl;
    return 0;
}

