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

const int MX = 200010;
int n, m;
vector<vector<int>> g(MX), large_g(MX);
vector<int> col(MX, 1), X(MX), Y(MX);
vector<int> change_time(MX, 0);

int large_update(int x, int y, int t) {
    int res = col[x];
    col[x] = y;
    change_time[x] = t;
    for (auto v : large_g[x]) {
        col[v] = y;
    }
    return res;
}

int small_update(int x, int y, int t) {
    int max_t = change_time[x];
    for (auto nv: g[x]) {
        chmax(max_t, change_time[nv]);
        col[nv] = y;
    }
    int res = max_t == 0 ? 1 : Y[max_t-1];
    change_time[x] = t;
    return res;
}

int main() {
    cin >> n >> m;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    cin >> q;
    rep(i,q) {
        cin >> X[i] >> Y[i];
        --X[i];
    }
    int threshold = int(sqrt(2*m));
    // 各頂点から次数の大きい頂点への辺だけをもつグラフを作る
    rep(v,n) {
        for (auto nv: g[v]) {
            if (threshold <= g[nv].size()) {
                large_g[v].push_back(nv);
            }
        }
    }
    rep(i,q) {
        if (threshold <= g[X[i]].size()) {
            cout << large_update(X[i], Y[i], (i+1)) << endl;
        } else {
            cout << small_update(X[i], Y[i], (i+1)) << endl;
        }
    }
    return 0;
}