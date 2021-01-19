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
vector<P> edges;
bool bridge(int x, int y) {
    auto uf = dsu(n);
    for (auto e : edges) {
        if (e.first == x && e.second == y) continue;
        uf.merge(e.first, e.second);
    }
    return !uf.same(x, y);
}

int main() {
    cin >> n >> m;
    edges.resize(m);
    rep(i,m) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--, edges[i].second--;
    }
    int ans = 0;
    for (auto e : edges) {
        if (bridge(e.first, e.second)) ans++;
    }
    cout << ans << endl;
    return 0;
}