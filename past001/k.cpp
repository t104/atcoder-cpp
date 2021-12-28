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

vector<vector<int>> g;
vector<int> euler;

void dfs(int v) {
    euler.push_back(v);
    for (auto &nv : g[v]) {
        dfs(nv);
    }
    euler.push_back(v);
}

int main() {
    int n;
    cin >> n;
    int root;
    g.resize(n);
    rep(i,n) {
        int p;
        cin >> p;
        if (p == -1) {
            root = i;
        } else g[p-1].push_back(i);
    }
    dfs(root);
    vector<P> order(n, make_pair(-1, -1));
    rep(i, 2*n) {
        int v = euler[i];
        if (order[v].first == -1) {
            order[v].first = i;
        } else {
            order[v].second = i;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (order[b].first < order[a].first && order[a].second < order[b].second) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

