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

const int max_n = 3005;
const int mod = 1000000007;
int dp[max_n][max_n];

int main() {
    int n;
    string s;
    cin >> n >> s;

    rep(i,n) dp[0][i] = 1;

    rep(i,n-1) {
        int sum[max_n];
        sum[0] = 0;
        rep(j,n-i) sum[j+1] = (sum[j] + dp[i][j]) % mod;

        if (s[i] == '<') {
            for (int j = 0; j < n-i; ++j) {
                dp[i+1][j] = (sum[n-i] - sum[j+1] + mod) % mod;
            }
        }
        else {
            rep(j,n-i) {
                dp[i+1][j] = sum[j+1];
            }
        }
    }

    cout << dp[n-1][0] << endl;

    return 0;
}