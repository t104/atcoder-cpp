#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
using mint = modint;
const int MX = 105;
const int MOD = 10000;
int dp[MX][3][2];

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> given(n, -1);
    rep(i,k) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        given[a] = b;
    }
    if (given[0] == -1) {
        rep(i,3) {
            dp[1][i][0] = 1;
        }
    }
    else {
        dp[1][given[0]][0] = 1;
    }
    rep(i,n) {
        if (0 <= given[i]) {
            rep(j,3) {
                if (given[i] == j) {
                    dp[i+1][j][1] += dp[i][j][0];
                    dp[i+1][j][1] %= MOD;
                }
                else {
                    dp[i+1][given[i]][0] += dp[i][j][0];
                    dp[i+1][given[i]][0] += dp[i][j][1];
                    dp[i+1][given[i]][0] %= MOD;
                }
            }
            continue;
        }
        rep(j,3) {
            rep(k,3) {
                if (j == k) {
                    dp[i+1][j][1] += dp[i][k][0];
                    dp[i+1][j][1] %= MOD;
                }
                else {
                    dp[i+1][j][0] += dp[i][k][0];
                    dp[i+1][j][0] += dp[i][k][1];
                    dp[i+1][j][0] %= MOD;
                }
            }
        }
    }
    
    int ans = 0;
    rep(i,3) {
        rep(j,2) {
            ans += dp[n][i][j];
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}