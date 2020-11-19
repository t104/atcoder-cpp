#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

const int mod = 1000000007;
const int max_dk = 10005;
const int max_d = 105;
int k[max_dk];

// i 桁目まで、k より小さい、余り
int dp[max_dk][2][max_d];

int main() {
    string s;
    int d;
    cin >> s >> d;
    int n = s.size();
    rep(i,n) k[i] = s[i] - '0';

    dp[0][0][0] = 1;
    rep(i,n) rep(di,d) {
        // dig : 次のけた
        // kより小さい
        rep(dig,10) {
            dp[i+1][1][(di+dig)%d] += dp[i][1][di];
            dp[i+1][1][(di+dig)%d] %= mod;
        }

        // i 桁目が一致しない & i 桁目はk[i]より小さい => k より小さいことが確定
        rep(dig, k[i]) {
            dp[i+1][1][(di+dig)%d] += dp[i][0][di];
            dp[i+1][1][(di+dig)%d] %= mod;
        }

        // i+1 桁目まで一致している <= i桁目まで一致している
        dp[i+1][0][(di+k[i])%d] += dp[i][0][di];
        dp[i+1][0][(di+k[i])%d] %= mod;
    }
    int ans = (dp[n][0][0] + dp[n][1][0] - 1 + mod) % mod;
    rep(i,n+1) {
        rep(di, d) cout << dp[i][0][di] << ' ';
        cout << endl;
    }
    cout << endl;
    rep(i,n+1) {
        rep(di, d) cout << dp[i][1][di] << ' ';
        cout << endl;
    }
    return 0;
}