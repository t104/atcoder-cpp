#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a.at(i);
    rep(i,m) cin >> b.at(i);
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
    dp[0][0] = 0;
    rep(i,n+1) rep(j,m+1) {
        if (i < n) {
            chmin(dp[i+1][j], dp[i][j] + 1);
        }
        if (j < m) {
            chmin(dp[i][j+1], dp[i][j] + 1);
        }
        if (i < n && j < m) {
            int cost = 0;
            if (a[i] != b[j]) ++cost;
            chmin(dp[i+1][j+1], dp[i][j] + cost);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}