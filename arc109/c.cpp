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

char winner(char a, char b) {
    if (a == 'R' && b == 'P') {
        return b;
    }
    if (a == 'P' && b == 'S') {
        return b;
    }
    if (a == 'S' && b == 'R') {
        return b;
    }
    return a;
}

int modpow(int base, int p, int mod) {
    if (p == 0) return 1;
    if (p == 1) return base % mod;
    if (p % 2 == 1) return (base * modpow(base, p-1, mod)) % mod;
    int t = modpow(base, p/2, mod);
    return (t*t) % mod;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<char>> dp(k+1, vector<char>(n));
    rep(i,n) {
        dp[0][i] = s[i];
    }
    for (int i = 1; i <= k; ++i) {
        rep(j,n) {
            dp[i][j] = winner(dp[i-1][j], dp[i-1][(j + modpow(2, i-1, n)) % n]);
        }
    }
    cout << dp[k][0] << endl;
    return 0;
}