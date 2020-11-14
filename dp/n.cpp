#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const ll LINF = 1LL<<60;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);

    vector<vector<ll>> dp(n,vector<ll>(n, LINF));
    vector<vector<ll>> sum(n, vector<ll>(n));
    rep(i,n) sum[0][i] = a[i];
    rep(i,n) dp[0][i] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; i+j < n; ++j) {
            sum[i][j] = sum[i-1][j] + sum[0][i+j];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; i+j < n; ++j) {
            for (int k = 0; k < i; ++k) {
                chmin(dp[i][j], sum[i][j] + dp[k][j] + dp[i-k-1][j+k+1]);
            }
        }
    }
    cout << dp[n-1][0] << endl;
    return 0;
}