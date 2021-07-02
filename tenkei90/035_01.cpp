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

const int MX = 100010;

int n;
vector<vector<int>> g(MX);
vector<int> exists(MX);
vector<int> dp(MX);

void dfs(int v, int p) {
    dp[v] += exists[v];
    for (auto nv : g[v]) {
        if (nv == p) continue;
        dfs(nv, v);
        dp[v] += dp[nv];
    }
}

void solve() {
    int vn;
    cin >> vn;
    rep(i,n) {
        exists[i] = 0;
        dp[i] = 0;
    }
    rep(i,vn) {
        int vi;
        cin >> vi;
        vi--;
        exists[vi]++;
    }
    dfs(0, -1);
    int ans = 0;
    rep(i,n) {
        ans += (0 < dp[i] && dp[i] < vn);
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}