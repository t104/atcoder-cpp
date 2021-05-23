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

using mint = modint998244353;

void ng() {
    cout << 0 << endl;
    exit(0);
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i,h) cin >> g[i];
    int x = h+w-1;
    // . -> 0, R -> 1, B -> 2
    vector<int> col(x);
    rep(i,h) rep(j,w) {
        if (g[i][j] == 'R') {
            if (col[i+j] == 2) ng();
            col[i+j] = 1;
        }
        if (g[i][j] == 'B') {
            if (col[i+j] == 1) ng();
            col[i+j] = 2;
        }
    }
    mint ans = 1;
    for (auto c: col) {
        if (c == 0) ans *= 2;
    }
    cout << ans.val() << endl;

    return 0;
}