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

int n, m, k;
vector<int> a;
struct edge {
    int to, id;
    edge(int to, int id): to(to), id(id) {}
};
vector<vector<edge>> g;
vector<int> cnt;

void dfs(int v, int p, int &goal, vector<int> &r) {
    if (v == goal) {
        for (auto &e: r) {
            cnt[e]++;
        }
        return;
    }
    for (auto &e: g[v]) {
        if (e.to == p) continue;
        r.push_back(e.id);
        dfs(e.to, v, goal, r);
        r.pop_back();
    }
}

using mint = modint998244353;
vector<map<int, mint>> dp;

int main() {
    cin >> n >> m >> k;
    a.resize(m);
    g.resize(n);
    cnt.resize(n-1);
    rep(i,m) {
        cin >> a[i];
        a[i]--;
    }
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    rep(i,m-1) {
        vector<int> r;
        dfs(a[i], -1, a[i+1], r);
    }
    dp.resize(n);
    dp[0][0] = 1;
    rep(i,n-1) {
        for (auto &p: dp[i]) {
            dp[i+1][p.first + cnt[i]] += p.second;
            dp[i+1][p.first - cnt[i]] += p.second;
        }
    }
    if (dp[n-1].count(k) == 0) {
        cout << 0 << endl;
    } else {
        cout << dp[n-1][k].val() << endl;
    }

    return 0;
}

