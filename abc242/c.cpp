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

mint dp[1000010][10];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < 10; ++i) dp[0][i] = 1;
    rep(i,n) {
        for (int j = 1; j < 10; ++j) {
            if (1 <= j-1) {
                dp[i+1][j-1] += dp[i][j];
            }
            if (j+1 <= 9) {
                dp[i+1][j+1] += dp[i][j];
            }
            dp[i+1][j] += dp[i][j];
        }
    }
    mint ans = 0;
    for (int i = 1; i < 10; ++i) {
        ans += dp[n-1][i];
    }
    cout << ans.val() << endl;
    return 0;
}

