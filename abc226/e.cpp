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

using mint = modint998244353;

int main() {
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    vector<int> u(m), v(m);
    vector<int> edge_count(n);

    rep(i,m) {
        cin >> u[i] >> v[i];
        --u[i], --v[i];
        uf.merge(u[i], v[i]);
    }

    rep(i,m) {
        edge_count[uf.leader(u[i])]++;
    }

    for (auto &g : uf.groups()) {
        if (g.size() != edge_count[uf.leader(g[0])]) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << mint(2).pow(uf.groups().size()).val() << endl;
    return 0;
}

