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

using mint = modint1000000007;

const string target = "atcoder";

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<mint>> dp(n+1, vector<mint>(8));
    dp[0][0] = 1;
    rep(i,n) {
        rep(j,7) {
            dp[i+1][j] += dp[i][j];
            if (s[i] == target[j]) {
                dp[i+1][j+1] += dp[i][j];
            }
        }
        dp[i+1][7]  += dp[i][7];
    }
    cout << dp[n][7].val() << endl;
    return 0;
}