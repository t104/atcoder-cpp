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

struct Edge {
    int to;
    ll c, d;
    Edge(int to, ll c, ll d): to(to), c(c), d(d) {}
    ll cost (ll t) {
        return c + d / (t + 1LL);
    }
    ll fastest(ll t) {
        double rtd = sqrt((double) d);
        ll res = t + cost(t);
        for (double d = -2; d <= 2; d += 1.0) {
            ll start = t + floor(d + rtd);
            if (t <= start) chmin(res, start + cost(start));
        }
        return res;
    }
};

vector<vector<Edge>> g;

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    rep(i,m) {
        int a, b;
        ll c, d;
        cin >> a >> b >> c >> d;
        --a, --b;
        g[a].emplace_back(b, c, d);
        g[b].emplace_back(a, c, d);
    }
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, 0);
    vector<ll> ans(n, LINF);
    ans[0] = 0;
    while (que.size()) {
        auto [now, v] = que.top(); que.pop();
        if (ans[v] < now) continue;
        for (auto e: g[v]) {
            ll nt = e.fastest(now);
            if (chmin(ans[e.to], nt)) {
                que.emplace(nt, e.to);
            }
        }
    }
    cout << (ans[n-1] == LINF ? -1 : ans[n-1]) << endl;
    return 0;
    
}