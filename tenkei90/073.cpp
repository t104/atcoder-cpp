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

vector<vector<mint>> dp;
vector<int> group;
vector<vector<int>> g;

void dfs(int v, int p) {
    dp[v][group[v]] = 1;
    dp[v][2] = 1;
    for (auto nv: g[v]) {
        if (nv == p) continue;
        dfs(nv, v);
        dp[v][group[v]] *= dp[nv][group[v]] + dp[nv][2];
        dp[v][2] *= dp[nv][group[v]] + dp[nv][(group[v]+1)%2] +  2 * dp[nv][2];
    }
    dp[v][2] -= dp[v][0] + dp[v][1];
}

int main() {
    int n;
    cin >> n;
    group.resize(n);
    g.resize(n);
    rep(i,n) {
        char c;
        cin >> c;
        if (c == 'b') group[i] = 1;
    }
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dp.resize(n, vector<mint>(3));
    dfs(0,-1);
    cout << dp[0][2].val() << endl;

    // rep(i,n) {
    //     rep(j,3) {
    //         cout << dp[i][j].val() << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;
}