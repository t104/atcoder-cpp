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

struct edge {
    int to;
    bool used;
    edge(int to, bool used) : to(to), used(used) {}
};
vector<vector<edge>> a;
int n, q;

void dfs(int v, bool &ok) {
    if (v == n+1) {
        ok = true;
    }
    for (auto &nv : a[v]) {
        if (nv.used) continue;
        nv.used = true;
        dfs(nv.to, ok);
    }
}

int main() {
    cin >> n >> q;
    a.resize(n+2);
    rep(i,q) {
        int l, r;
        cin >> l >> r;
        a[l].emplace_back(r+1, false);
        a[r+1].emplace_back(l, false);
    }
    a[0].emplace_back(1, false);
    bool ok = false;
    dfs(0, ok);
    cout << (ok ? "Yes" : "No") << endl;;
    return 0;
}

