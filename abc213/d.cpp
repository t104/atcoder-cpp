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
vector<vector<int>> g;
vector<int> visited;
int n;
vector<int> ans;
const int not_visited = -2;

void dfs(int v, int p) {
    ans.push_back(v);
    if (visited[v] == not_visited) visited[v] = p;
    for (auto nv: g[v]) {
        if (visited[nv] == not_visited) {
            dfs(nv, v);
            return;
        }
    }
    if (v == 0) return;
    dfs(visited[v], v);
}

int main() {
    cin >> n;
    g.resize(n);
    visited.resize(n, not_visited);
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i,n) {
        sort(g[i].begin(), g[i].end());
    }
    dfs(0, -1);
    for (auto a: ans) cout << a+1 << endl;

    return 0;
}

