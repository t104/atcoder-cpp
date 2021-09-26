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

int main() {
    int n, a, b, m;
    cin >> n >> a >> b >> m;
    --a, --b;
    vector<vector<int>> g(n);
    vector<int> dist(n, INF);
    vector<mint> paths(n);
    dist[a] = 0;
    paths[a] = 1;
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, a);
    while (que.size()) {
        auto [d, v] = que.top(); que.pop();
        if (dist[v] < d) continue;
        for (auto nv: g[v]) {
            if (d + 1 < dist[nv]) {
                dist[nv] = d + 1;
                paths[nv] = paths[v];
                que.emplace(d + 1, nv);
            } else if (dist[nv] == d + 1) {
                paths[nv] += paths[v];
            }
        }
    }
    assert(dist[b] < INF);
    cout << paths[b].val() << endl;
    return 0;
}