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


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<P>> g(n);
    vector<int> dist(n, INF);
    dist[0] = 0;
    vector<vector<int>> hist(n);
    hist[0] = {0};
    vector<P> edges(m);
    rep(i,m) {
        int s, t;
        cin >> s >> t;
        --s, --t;
        edges[i] = {s,t};
        g[s].emplace_back(t, i);
    }
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, 0);
    while (que.size()) {
        auto [v, w] = que.top(); que.pop();
        if (dist[v] < w) continue;
        for (auto [nv, i]: g[v]) {
            int nw = w + 1;
            if (chmin(dist[nv], nw)) {
                que.emplace(nv, nw);
                hist[nv] = hist[v];
                hist[nv].push_back(i);
            }
        }
    }
    rep(i,m) {
        bool visit = false;
        for (auto j: hist[n-1]) {
            if (i == j) visit = true;
        }
        if (!visit) {
            cout << (dist[n-1] == INF ? -1 : dist[n-1]) << endl;
            continue;
        }
        que.emplace(0, 0);
        vector<int> d(n, INF);
        d[0] = 0;
        while (que.size()) {
            auto [v,w] = que.top(); que.pop();
            if (d[v] < w) continue;
            for (auto [nv, j]: g[v]) {
                if (i == j) continue;
                int nw = w + 1;
                if (chmin(d[nv], nw)) {
                    que.emplace(nv, nw);
                }
            }
        }
        cout << (d[n-1] == INF ? -1 : d[n-1]) << endl;
    }
    return 0;
}

