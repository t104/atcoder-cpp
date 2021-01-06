#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;

int n,k;

struct edge{
    int to, cost;
    edge(int to, int cost): to(to), cost(cost) {}
};

vector<vector<edge>> graph;


int dijkstra(int s, int g) {
    vector<int> cost(n, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    cost[s] = 0;
    que.emplace(s, 0);
    while (!que.empty()) {
        auto [v, c] =  que.top(); que.pop();
        if (cost[v] < c) continue;
        for (auto e: graph[v]) {
            int nc = c + e.cost;
            if (nc < cost[e.to]) {
                cost[e.to] = nc;
                que.emplace(e.to, nc);
            }
        }
    }
    
    int dst = cost[g];
    if (dst == INF) dst = -1;
    return dst;
}

int main() {
    cin >> n >> k;
    graph.resize(n);

    rep(i,k) {
        int q;
        cin >> q;
        if (q) {
            int s, g, c;
            cin >> s >> g >> c;
            --s, --g;
            graph[s].emplace_back(g, c);
            graph[g].emplace_back(s, c);
        }
        else {
            int s, g;
            cin >> s >> g;
            --s, --g;
            cout << dijkstra(s, g) << endl;
        }
    }
    return 0;
}