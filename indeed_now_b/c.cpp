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
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    priority_queue<int, vector<int>, greater<int>> que;
    vector<int> ans;
    vector<bool> visited(n, false);
    visited[0] = true;
    que.push(0);
    while (que.size()) {
        int v = que.top(); que.pop();
        ans.push_back(v);
        visited[v] = true;
        for (auto e: g[v]) {
            if (!visited[e]) que.push(e);
        }
    }
    rep(i, ans.size()) {
        cout << ans[i] + 1;
        if (i == ans.size() - 1) cout << endl;
        else cout << ' ';
    }

    return 0;
}