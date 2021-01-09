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
using P = pair<int,int>;

struct taxi {
    int to, dis;
    ll cost;
    taxi(int to, int dis, ll cost): to(to), dis(dis), cost(cost) {}

    bool operator<(const taxi &rhs) const {
        return cost < rhs.cost;
    }
    bool operator>(const taxi &rhs) const {
        return rhs.cost < cost;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> cost(n);
    vector<int> r(n);
    rep(i,n) cin >> cost[i] >> r[i];
    vector<vector<int>> graph(n);
    rep(i,k) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    priority_queue<taxi, vector<taxi>, greater<taxi>> que;
    vector<vector<ll>> ans(n, vector<ll>(n, LINF));
    ans[0][0] = 0;
    que.emplace(0,0,0);
    while (que.size()) {
        taxi now = que.top(); que.pop();
        if (ans[now.to][now.dis] < now.cost) continue;
        for (auto nv : graph[now.to]) {
            if (0 < now.dis) {
                if (chmin(ans[nv][now.dis-1], now.cost))
                    que.emplace(nv, now.dis - 1, now.cost);
            }
            
            if (chmin(ans[nv][r[now.to]-1], now.cost + cost[now.to])) {
                que.emplace(nv, r[now.to] - 1, now.cost + cost[now.to]);
            }
        }
    }

    ll res = LINF;
    rep(i,n) chmin(res, ans[n-1][i]);
    cout << res << endl;
    return 0;
}
