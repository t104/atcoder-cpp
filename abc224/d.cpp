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
using P = pair<int,vector<int>>;

int main() {
    int m;
    cin >> m;
    const int n = 9;
    vector<vector<int>> g(n);
    vector<int> p(n, 8);
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i,n-1) {
        int pos;
        cin >> pos;
        p[pos-1] = i;
    }
    map<vector<int>,int> mp;
    vector<int> init(n);
    rep(i,n) init[i] = i;
    priority_queue<P, vector<P>, greater<P>> que;
    mp[init] = 0;
    que.emplace(0, init);
    while (que.size()) {
        auto [count, now] = que.top(); que.pop();
        if (mp.count(now) && mp.at(now) < count) continue;
        int np = 0;
        rep(i,n) {
            if (now[i] == 8) np = i;
        }
        for (auto &nv : g[np]) {
            auto next = now;
            swap(next[np], next[nv]);
            if (mp.count(next)) continue;
            mp[next] = count + 1;
            que.emplace(count + 1, next);
        }
    }
    if (mp.count(p)) {
        cout << mp.at(p) << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}