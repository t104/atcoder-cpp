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


int n, m;
vector<vector<int>> g;
vector<int> used;

bool dfs(int v, int p) {
    used[v] = 1;
    for (auto &nv : g[v]) {
        if (nv == p) continue;
        if (used[nv]) {
            return true;
        }
        dfs(nv, v);
    }
    return false;
}

int main() {
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i,n) {
        if (2 < g[i].size()) {
            cout << "No" << endl;
            return 0;
        }
        if (!used[i]) {
            if (dfs(i, -1)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}

