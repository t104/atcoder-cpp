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
const int MX = 200005;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    vector<mint> dp(n);
    vector<int> last(MX, -1);
    dp[0] = 1;
    last[c[0]] = 0;
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i-1];
        if (last[c[i]] != -1 && last[c[i]] + 1 < i)
            dp[i] += dp[last[c[i]]];
        last[c[i]] = i;
    }
    cout << dp[n-1].val() << endl;
    return 0;
}