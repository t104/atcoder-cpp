#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<ll, int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

struct Edge{
    int to;
    ll w;
    Edge(int to=0, ll w=0): to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

void Dijkstra(int s, Graph &G, vector<ll> &cost) {
    int n = G.size();
    cost.assign(n, LINF);
    cost.at(s) = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(make_pair(0, s));
    while (!que.empty()) {
        auto [w, v] = que.top(); que.pop();
        if (cost.at(v) < w) continue;
        for (auto ne : G.at(v)) {
            if (cost.at(ne.to) <= w + ne.w) continue;
            cost.at(ne.to) = w + ne.w;
            que.emplace(w + ne.w, ne.to);
        }
    }
}

int main() {
    int n, m;
    int xab, xbc, xca;
    string s;
    cin >> n >> m >> xab >> xca >> xbc >> s;

    Graph G(n+6);
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        G.at(a).emplace_back(b, c);
        G.at(b).emplace_back(a, c);
    }
    
    G.at(n).emplace_back(n+4, xab);
    G.at(n).emplace_back(n+5, xca);
    G.at(n+1).emplace_back(n+5, xbc);
    G.at(n+1).emplace_back(n+3, xab);
    G.at(n+2).emplace_back(n+3, xca);
    G.at(n+2).emplace_back(n+4, xbc);

    rep(i,n) {
        int j = s.at(i) - 'A';
        G.at(i).emplace_back(n+j, 0);
        G.at(n+3+j).emplace_back(i, 0);
    }

    vector<ll> cost;
    Dijkstra(0, G, cost);
    cout << cost.at(n-1) << endl;
    return 0;
}