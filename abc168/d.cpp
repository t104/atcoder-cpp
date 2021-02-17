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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> que;
    vector<int> route(n), dist(n, INF);
    que.push(0);
    dist[0] = 0;
    while(que.size()) {
        int now = que.front(); que.pop();
        for (auto e : g[now]) {
            if (chmin(dist[e], dist[now] + 1)) {
                que.push(e);
                route[e] = now;
            }
        }
    }

    rep(i,n) {
        if (INF <= dist[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (int i = 1; i < n; ++i) {
        cout << route[i] + 1 << endl;
    }
    return 0;
}