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

int n, q;
vector<vector<int>> g;
vector<int> tp;

void dfs(int v, int t) {
    tp[v] = t;
    for (auto nv: g[v]) {
        if (0 <= tp[nv]) continue;
        dfs(nv, (t+1)%2);
    }
}

int main() {
    cin >> n >> q;
    g.resize(n);
    tp.resize(n, -1);
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0);
    while (q--) {
        int c, d;
        cin >> c >> d;
        --c, --d;
        if ((tp[c]+tp[d]) % 2 == 0) cout << "Town" << endl;
        else cout << "Road" << endl;
    }
    return 0;
}