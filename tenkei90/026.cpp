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

void dfs(vector<vector<int>> &g, vector<int> &group, int v, int p) {
    for (auto nv: g[v]) {
        if (nv == p) continue;
        group[nv] = (group[v] + 1) % 2;
        dfs(g, group, nv, v);
    }
}

int main() {
    int n;
    cin >> n;
    int m = n/2;
    vector<vector<int>> g(n);
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> group(n);
    dfs(g, group, 0, -1);
    int cnt = 0;
    rep(i,n) cnt += group[i];
    if (m <= cnt) {
        for (int i = 0; i < n && 0 < m; ++i) {
            if (group[i]) {
                cout << i + 1 << ' ';
                --m;
            }
        }
    }
    else {
        for (int i = 0; i < n && 0 < m; ++i) {
            if (group[i] == 0) {
                cout << i + 1 << ' ';
                --m;
            }
        }
    }
    cout << endl;
    return 0;
}