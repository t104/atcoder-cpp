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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), x(m);
    rep(i,m) {
        cin >> a[i] >> b[i] >> x[i];
        --a[i], --b[i];
    }
    vector<vector<int>> dp(n, vector<int>(n));
    rep(i,m) {
        chmax(dp[a[i]][b[i]], x[i] + 1);
    }

    for (int i = 1; i < n; ++i) {
        rep(j,n) {
            chmax(dp[i][j], dp[i-1][j] - 1);
            if (0 <= j-1) {
                chmax(dp[i][j], dp[i-1][j-1] - 1);
            }
        }
    }

    int ans = 0;
    rep(i,n) {
        for (int j = 0; j <= i; ++j) {
            if (dp[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}