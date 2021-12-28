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

int H, W;
int A[50][50];
int dp[3][50][50];

P d[] = {
    make_pair(1, 0),
    make_pair(0, 1),
    make_pair(-1, 0),
    make_pair(0, -1)
};

struct element {
    int c, h, w;
    element(int c, int h, int w) : c(c), h(h), w(w) {}

    bool operator>(const element &rhs) const {
        return rhs.c < c;
    }
};

int main() {
    cin >> H >> W;
    rep(i,H) rep(j, W) cin >> A[i][j];
    P start [3] = {
        make_pair(H-1, 0),
        make_pair(H-1, W-1),
        make_pair(0, W-1)
    };
    rep(i, 3) rep(j, 50) rep(k, 50) dp[i][j][k] = INF;
    rep(i, 3) {
        auto &[sh, sw] = start[i];
        dp[i][sh][sw] = 0;
        priority_queue<element, vector<element>, greater<element>> que;
        que.emplace(0, sh, sw);
        while (que.size()) {
            auto [ci, hi, wi] = que.top(); que.pop();
            for (auto &[dh, dw] : d) {
                int nh = hi + dh;
                int nw = wi + dw;
                if (in(nh, 0, H) && in(nw, 0, W)) {
                    int nc = ci + A[nh][nw];
                    if (chmin(dp[i][nh][nw], nc)) {
                        que.emplace(nc, nh, nw);
                    }
                }
            }
        }
    }
    int ans = INF;
    rep(i, H) rep(j, W) {
        int sum = 0;
        rep(k, 3) sum += dp[k][i][j];
        chmin(ans, sum - 2 * A[i][j]);
    }
    cout << ans << endl;
    return 0;
}

