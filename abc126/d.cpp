#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int max_n = 100005;

struct edge {
    int p, d;
    edge(int p, int d): p(p), d(d) {};
};

vector<int> ans(max_n);
vector<bool> visited(max_n);
vector<vector<edge>> tree(max_n);

void dfs(int now, int flg) {
    if (visited.at(now)) return;
    ans.at(now) = flg;
    visited.at(now) = true;
    for (auto e : tree.at(now)) {
        if (e.d%2 == 1) dfs(e.p, !flg);
        else dfs(e.p, flg);
    }
}

int main() {
    int n;
    cin >> n;
    rep(i,n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        tree.at(u).push_back(edge(v, w));
        tree.at(v).push_back(edge(u, w));
    }
    dfs(0, 0);
    rep(i,n) cout << ans.at(i) << endl;
    return 0;
}