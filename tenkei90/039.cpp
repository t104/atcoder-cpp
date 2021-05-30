#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL << 60)
#define rep(i, n) for(int i = 0; i < (n); ++i)
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2, typename T3>
inline bool in(T1 val, T2 l, T3 r) {
    return l <= val && val < r;
}
using ll = long long;
using ld = long double;
using P = pair<int, int>;

using Graph = vector<vector<int>>;

vector<ll> dp;
ll ans;

void dfs(Graph &g, int v, int p) {
    dp[v] = 1;
    for (auto nv: g[v]) {
        if (nv == p) continue;
        dfs(g, nv, v);
        dp[v] += dp[nv];
    }
}

int main() {
    int n;
    cin >> n;
    Graph g(n);
    dp.resize(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(g, 0, -1);
    ans = 0;
    rep(i,n) {
        ans += dp[i] * (n-dp[i]);
    }
    cout << ans << endl;
    return 0;
}