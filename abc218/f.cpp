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

struct Edge {
    int to, idx;
    ll w;

    Edge(int to, ll w): to(to), w(w) {}

    Edge(int idx, int to, ll w): idx(idx), to(to), w(w) {}

    bool operator<(const Edge &rhs) const {
        return w < rhs.w;
    }

    bool operator>(const Edge &rhs) const {
        return w < rhs.w;
    }
};

struct Node {
    int v;
    ll w;
    
    Node(int v, ll w): v(v), w(w) {}

    bool operator<(const Node &rhs) const {
        return w < rhs.w;
    }

    bool operator>(const Node &rhs) const {
        return w < rhs.w;
    }
};

struct Graph {
    vector<vector<Edge>> g;
    int size;
    vector<ll> dist;
    vector<vector<int>> hist;

    Graph(int n): size(n) {
        g.resize(n);
    }

    Graph(vector<vector<Edge>> g): g(g) {
        int size = (int) g.size();
    }

    void add_edge(int from, int to, ll w) {
        g[from].emplace_back(to, w);
    }

    void add_edge(int from, Edge e) {
        g[from].push_back(e);
    }

    void dijkstra(int s, int banned = -1) {
        dist.assign(size, LINF);
        hist.assign(size, vector<int>(0));
        priority_queue<Node, vector<Node>, greater<Node>> que;
        que.emplace(s, 0);
        dist[s] = 0;
        while (que.size()) {
            auto now = que.top(); que.pop();
            if (dist[now.v] < now.w) continue;
            for (auto e: g[now.v]) {
                if (e.idx == banned) continue;
                if (chmin(dist[e.to], now.w + e.w)) {
                    hist[e.to] = hist[now.v];
                    hist[e.to].push_back(e.idx);
                    que.emplace(e.to, now.w + e.w);
                }
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    rep(i,m) {
        int s, t;
        cin >> s >> t;
        --s, --t;
        g.add_edge(s, Edge(i, t, 1));
    }
    g.dijkstra(0);
    vector<int> hist = g.hist[n-1];
    ll dist = g.dist[n-1];
    rep(i,m) {
        bool visit = false;
        for (auto &v: hist) {
            if (i == v) visit = true;
        }
        if (!visit) {
            cout << (dist == LINF ? -1 : dist) << endl;
            continue;
        }
        g.dijkstra(0, i);
        cout << (g.dist[n-1] == LINF ? -1 : g.dist[n-1]) << endl;
    }
    return 0;
}

