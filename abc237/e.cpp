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
using P = pair<ll,int>;

vector<ll> h;

ll calc(int p1, int p2) {
    if (h[p1] < h[p2]) {
        return -2LL * (h[p2] - h[p1]);
    }
    return h[p1] - h[p2];
}

int main() {
    int n, m;
    cin >> n >> m;
    h.resize(n);
    vector<vector<int>> g(n);
    rep(i,n) cin >> h[i];
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> joy(n, -LINF);
    joy[0] = 0;
    priority_queue<P> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        auto [x, v] = que.top(); que.pop();
        if (x < joy[v]) continue;
        for (auto &nv : g[v]) {
            ll x2 = x + calc(v, nv);
            if (chmax(joy[nv], x2)) {
                que.emplace(x2, nv);
            }
        }
    }
    cout << *max_element(joy.begin(), joy.end()) << endl;
    return 0;
}

