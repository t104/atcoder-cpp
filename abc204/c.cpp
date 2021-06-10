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

vector<vector<int>>g;

void dfs(int v, int d, vector<int> &dist) {
    dist[v] = d;
    for (auto nv: g[v]) {
        if (d+1 < dist[nv]) {
            dfs(nv, d+1, dist);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
    }

    int ans = 0;
    rep(i,n) {
        vector<int> dist(n, INF);
        dfs(i, 0, dist);
        for (auto di: dist) {
            if (di < INF) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}