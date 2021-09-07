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
const int MX = 10;
mint dp[1005][1<<MX][MX+1];
int n;

void print() {
    rep(i,n+1) {
        rep(j,1<<MX) {
            rep(k,11) cout << dp[i][j][k].val() << ' ';
            cout << endl;
        }
        cout << "====================================" << endl;
    }
}

int main() {
    string s;
    cin >> n >> s;
    dp[0][0][0] = 1;
    rep(i,n) {
        int contest = s[i] - 'A';
        rep(j, 1<<MX) {
            rep(k, MX+1) {
                dp[i+1][j][k] += dp[i][j][k];
                if (contest+1 == k) {
                    dp[i+1][j][k] += dp[i][j][k];
                } else if ((~j>>contest)&1) {
                    dp[i+1][j|(1<<contest)][contest+1] += dp[i][j][k];
                }
            }
        }
    }
    mint ans = 0;
    for (int i = 1; i <= MX+1; ++i) {
        for (int j = 1; j < (1<<10); ++j) {
            ans += dp[n][j][i];
        }
    }
    cout << ans.val() << endl;
    
    return 0;
}

