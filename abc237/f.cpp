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

using mint = modint998244353;
const int MX = 1010;
mint dp[MX][12][12][12];

int main() {
    int n, m;
    cin >> n >> m;
    dp[0][m+1][m+1][m+1] = 1;
    rep(i,n) {
        for (int a1 = 1; a1 <= m+1; ++a1)
            for(int a2 = 1; a2 <= m+1; ++a2)
                for (int a3 = 1; a3 <= m+1; ++a3)
                    for (int x = 1; x <= m; ++x) {
                        if (x <= a1) dp[i+1][x][a2][a3] += dp[i][a1][a2][a3];
                        else if (x <= a2) dp[i+1][a1][x][a3] += dp[i][a1][a2][a3];
                        else if (x <= a3) dp[i+1][a1][a2][x] += dp[i][a1][a2][a3];
                    }
    }
    mint ans = 0;
    for (int a1 = 1; a1 <= m; ++a1)
        for (int a2 = 1; a2 <= m; ++a2)
            for (int a3 = 1; a3 <= m; ++a3)
                ans += dp[n][a1][a2][a3];
    cout << ans.val() << endl;
    return 0;
}