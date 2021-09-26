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

mint dp[100010][10];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    dp[0][a[0]] = 1;
    for (int i = 1; i < n; ++i) {
        rep(j, 10) {
            int s = (j + a[i]) % 10;
            dp[i][s] += dp[i-1][j];
            int p = (j * a[i]) % 10;
            dp[i][p] += dp[i-1][j];
        }
    }
    rep(i,10) {
        cout << dp[n-1][i].val() << endl;
    }
    return 0;
}

