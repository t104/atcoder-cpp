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
using P = pair<int,int>;

int n, m;


struct Edge{
    int to, w;
    Edge(int to, int w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

Graph g;
vector<vector<int>> dp;

void Dijkstra(int s) {
    priority_queue<P,vector<P>,greater<P>> que;
    que.emplace(0,s);
    while (!que.empty()) {
        auto [w, v] = que.top(); que.pop();
        if (dp[s][v] < w) continue;
        for (auto e : g[v]) {
            if (chmin(dp[s][e.to], w + e.w)) {
                que.emplace(w + e.w, e.to);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    g.resize(n);
    dp.resize(n, vector<int>(n, INF));
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].emplace_back(b, c);
    }
    rep(i,n) Dijkstra(i);
    rep(i,n) {
        if (dp[i][i] < INF) {
            cout << dp[i][i] << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}