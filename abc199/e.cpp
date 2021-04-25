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


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<P>> cs(n+1);
    rep(i,m) {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        cs[x].emplace_back(y,z);
    }
    vector<ll> dp(1<<n);
    dp[0] = 1;
    rep(i,n) {
        for (int s = (1<<n)-1; 0 <= s; --s) {
            rep(j,n) {
                if (~(s>>j)&1) dp[s|(1<<j)] += dp[s];
            }
        }
        for (auto c: cs[i]) {
            rep(s,1<<n) {
                int t = s & ((1<<c.first)-1);
                if (c.second < __builtin_popcount(t)) dp[s] = 0;
            }
        }
    }
    cout << dp.back() << endl;
    return 0;
}