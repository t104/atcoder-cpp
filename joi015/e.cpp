#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<ll,int>;

int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    ll low, high;
    cin >> low >> high;
    vector<int> dis(n, INF);

    queue<int> que;
    rep(i,k) {
        int z;
        cin >> z;
        --z;
        dis[z] = 0;
        que.push(z);
    }

    vector<ll> cost(n, LINF);
    vector<int> prev(n);
    cost[0] = 0;
    vector<vector<int>> graph(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (auto next : graph[v]) {
            if (dis[v] + 1 < dis[next]) {
                dis[next] = dis[v] + 1;
                que.push(next);
            }
        }
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [c, v] = pq.top(); pq.pop();
        if (cost[v] < c) continue;
        for (auto next: graph[v]) {
            if (dis[next] == 0) continue;
            ll p = dis[next] <= s ? high : low;
            if (next == n-1) {
                if (c < cost[next]) {
                    cost[next] = c;
                    prev[next] = v;
                }
                continue;
            }
            if (c + p < cost[next]) {
                cost[next] = c + p;
                prev[next] = v;
                pq.emplace(c+p, next);
            }
        }
    }

    // rep(i,n) printf("%d %d\n", i, prev[i]);
    cout << cost[n-1] << endl;

    return 0;
}