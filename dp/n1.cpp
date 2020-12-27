// https://www.youtube.com/watch?v=YNT_iTpSWGI
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;

int n;
ll sum[440][440];
ll dp[440][440];
ll a[440];

int main() {
    cin >> n;
    rep(i,n) cin >> a[i];
    rep(l, n) {
        sum[l][l+1] = a[l];
        for (int r = l+2; r <= n; ++r) {
            sum[l][r] = sum[l][r-1] + a[r-1];
        }
    }

    for (int width = 2; width <= n; ++width) {
        for (int l = 0; l + width <= n; ++l) {
            int r = l + width;
            dp[l][r] = LINF;
            for (int m = l + 1; m < r; ++m) {
                chmin(dp[l][r], dp[l][m] + dp[m][r] + sum[l][r]);
            }
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}