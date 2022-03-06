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

// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
const int MAX_N = 1000005;
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
  mint p(int n, int k) {
    return fact[n]*ifact[n-k];
  }
} c(MAX_N);

mint dp[55][55][55];

mint cnt(int h, int w, int n) {
    if (h*w < n) return mint(0);
    if (dp[h][w][n] != 0) return dp[h][w][n];
    mint res = c(h*w, n);
    for (int i = 1; i <= h; ++i) {
        for (int j = n/i; j <= w; ++j) {
            if (i == h && j == w) continue;
            res -= cnt(i, j, n) * c(h, i) * c(w, j);
        }
    }
    // cout << h << ' ' << w << ' '  << n << ' ' << res.val() << endl;
    return dp[h][w][n] = res;
}

int main() {
    int N, M, B, W;
    cin >> N >> M >> B >> W;
    rep(i,N) rep(j,M) dp[i][j][0] = 1;
    // cout << cnt(2, 2, 2).val() << endl;
    mint ans = 0;
    for (int bh = 0; bh <= N; ++bh) {
        for (int wh = 0; bh + wh <= N; ++wh) {
            for (int bw = 0; bw <= M; ++bw) {
                for (int ww = 0; bw + ww <= M; ++ww) {
                    if (bh * bw < B || wh * ww < W) continue;
                    if (B < max(bh, bw) || W < max(wh, ww)) continue;
                    ans += cnt(bh, bw, B) * cnt(wh, ww, W) * c(N, bh) * c(N-bh, wh) * c(M, bw) * c(M-bw, ww);
                }
            }
        }
    }
    cout << ans.val() << endl;
    return 0;
}

