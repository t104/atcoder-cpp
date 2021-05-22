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

struct node {
    int parent, depth;
    deque<int> dec;
    vector<int> child;
    node() {
        parent = -1;
        depth = 0;
    }
};

int n;
vector<node> g;

deque<int> dfs(int v, int d) {
    g[v].depth = d;
    deque<int> res;
    for (auto nv: g[v].child) {
        auto dec = dfs(nv, d+1);
        int sz = dec.size();
        rep(i,sz) {
            if (res.size() < i+1) res.push_front(0);
            res.front() += dec[i];
        }
    }
    g[v].dec = res;
    res.push_front(1);
    return res;
}

int main() {
    cin >> n;
    g.resize(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        p--;
        g[i].parent = p;
        g[p].child.push_back(i);
    }
    dfs(0,0);
    
    int q;
    cin >> q;
    rep(i,q) {
        int u, d;
        cin >> u >> d;
        --u;
        int ans = 0;
        if (d < g[u].depth) {
            cout << 0 << endl;
            continue;
        }
        if (d == g[u].depth) {
            cout << 1 << endl;
            continue;
        }
        d -= g[u].depth;
        cout << g[u].dec[d-1] << endl;
    }
    return 0;
}