#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int n, m;
vector<vector<P>> G;
vector<int> ans;    
vector<bool> visited;

void dfs(int now) {
    if (visited[now]) return;
    visited[now] = true;
    for (auto p : G[now]) {
        if (ans[p.first] == -1) {
            if (ans[now] != p.second) {
                ans[p.first] = p.second;
            }
            else {
                ans[p.first] = (p.second + 1) % n + 1;
            }
        }
        dfs(p.first);
    }
}

int main() {
    cin >> n >> m;
    G.resize(n);
    rep(i,m) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    
    ans.assign(n, -1);
    visited.assign(n, false);
    dfs(0);
    rep(i,n) {
        assert(0 < ans[i]);
        cout << ans[i] << endl;
    }
    return 0;
}