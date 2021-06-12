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
    queue<int> que;
    vector<int> qued(n);
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a == i || b == i) {
            que.push(i);
            qued[i] = 1;
        }
        g[a].push_back(i);
        g[b].push_back(i);
    }

    vector<int> ans;
    while (!que.empty()) {
        int v = que.front(); que.pop();
        ans.push_back(v);
        for (auto nv: g[v]) {
            if (qued[nv] == 1) continue;
            que.push(nv);
            qued[nv] = 1;
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans.size() == n) {
        for (auto ai: ans) cout << ai+1 << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}