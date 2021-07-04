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
vector<vector<int>> g(MX);
vector<int> col(MX, 1);

void solve() {
    int x, y;
    cin >> x >> y;
    --x;
    cout << col[x] << endl;
    col[x] = y;
    for (auto v: g[x]) {
        col[v] = y;
    }
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
    while (q--) solve();
    return 0;
}