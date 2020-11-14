#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using mint = modint1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a.at(i);
    int sum = 0;
    rep(i,n) sum += a.at(i);
    vector<vector<mint>> dp(n+1, vector<mint>(k+1));
    dp.at(0).at(0) = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0];
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
            if (0 <= j - a[i] - 1) dp[i][j] -= dp[i-1][j - a[i] - 1];
        }
    }
    // rep(i,n+1) rep(j,k+1) {
    //     printf("%d %d %d\n", i, j, dp[i][j].val());
    // }
    cout << dp.at(n).at(k).val() << endl;
    return 0;
}