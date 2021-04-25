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

int n, m;
vector<vector<int>> g;
vector<bool> visited;

void dfs(int v, vector<int> &h) {
    if (visited[v]) return;
    visited[v] = true;
    h.push_back(v);
    for (auto u: g[v]) {
        if (visited[u]) continue;
        dfs(u, h);
    }
}

void dfs2(int v, int s, vector<int> &col) {
    for (auto u: g[v]) {
        if (0 <= col[u]) continue;
        if (s&1) col[u] = (col[v]+2) % 3;
        else col[u] = (col[v]+1) % 3;
        s >>= 1;
        dfs2(u, s, col);
    }
}

int main() {
    cin >> n >> m;
    g.resize(n);
    visited.resize(n, false);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> cnt;

    rep(i,n) {
        vector<int> h;
        dfs(i,h);
        int sz = h.size();
        if (sz == 0) continue;
        ll ci = 0;
        rep(j,3) {
            vector<int> col(n,-1);
            col[h[0]] = j;
            for (int s = 0; s < (1<<(sz-1)); ++s) {
                dfs2(h[0], s, col);
                bool ok = true;
                for (auto hi: h) {
                    for (auto u: g[hi]) {
                        if (col[u] == col[hi]) ok = false;
                    }
                }
                if (ok) ci++;
            }
        }
        cnt.push_back(ci);
    }

    ll ans = 1;
    for (auto c: cnt) ans *= c;
    cout << ans << endl;

    return 0;
}