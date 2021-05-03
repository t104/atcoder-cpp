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

int dp[1000005][2];

int solve(string s) {
    reverse(s.begin(), s.end());
    s += '0';
    int n = s.size();
    rep(i,n+1) rep(j,2) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,n) rep(j,2) {
        int x = s[i] - '0';
        x += j;
        rep(a, 10) {
            int ni = i+1, nj = 0;
            int b = a-x;
            if (b < 0) {
                nj = 1;
                b += 10;
            }
            chmin(dp[ni][nj], dp[i][j] + a + b);
        }
    }
    return dp[n][0];
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}