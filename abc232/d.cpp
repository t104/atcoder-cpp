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

P d[] = {
    {0, 1},
    {1, 0}
};

struct element {
    int h, w, p;
    element(int p, int h, int w) : h(h), w(w), p(p) {}
    bool operator<(const element &rhs) const {
        return p < rhs.p;
    }
    bool operator>(const element &rhs) const {
        return p > rhs.p;
    }
};

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> grid(h, vector<int>(w));
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    priority_queue<element, vector<element>, greater<element>> que;
    que.emplace(1, 0, 0);
    grid[0][0] = 1;
    while (que.size()) {
        auto now = que.top(); que.pop();
        for (auto [dh, dw] : d) {
            int nh = now.h + dh;
            int nw = now.w + dw;
            int np = now.p + 1;
            if (in(nh, 0, h) && in(nw, 0, w) && c[nh][nw] == '.') {
                if (chmax(grid[nh][nw], np)) {
                    que.emplace(now.p + 1, nh, nw);
                }
            }
        }
    }
    int ans = 0;
    rep(i,h) rep(j,w) {
        chmax(ans, grid[i][j]);
    }
    cout << ans << endl;
    return 0;
}

