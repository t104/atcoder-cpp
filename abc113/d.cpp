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

using mint = modint1000000007;

int h, w, k;
vector<vector<int>> cnt(8, vector<int>(2));
vector<vector<int>> mv(8, vector<int>(3));

int dfs(int wi, int now) {
    if (wi == w-2) {
        cnt[wi][now]++;
        return 1;
    }

    int res = 0;
    if (now == 0) {
        res += dfs(wi+1, 1);
    }
    res += dfs(wi+1, 0);
    cnt[wi][now] += res;
    return res;
}

vector<vector<mint>> dp(105, vector<mint>(8));

int main() {
    cin >> h >> w >> k;
    if (w == 1) {
        cout << 1 << endl;
        return 0;
    }
    rep(i,2) dfs(0,i);
    rep(i,w) {
        if (0 < i) {
            mv[i][0] = cnt[i-1][1];
            if (i < w-1) mv[i][1] = cnt[i][0] - cnt[i-1][1];
            else mv[i][1] = cnt[i-1][0];
        }
        else {
            mv[i][1] = cnt[i][0];
        }
        mv[i][2] = cnt[i][1];
    }

    dp[0][0] = 1;
    rep(i,h) {
        rep(j,w) {
            if (0 < j) dp[i+1][j-1] += dp[i][j] * mv[j][0];
            dp[i+1][j] += dp[i][j] * mv[j][1];
            if (j < w-1) dp[i+1][j+1] += dp[i][j] * mv[j][2];
        }
    }
    cout << dp[h][k-1].val() << endl;
    return 0;
}