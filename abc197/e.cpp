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
using P = pair<ll,ll>;

const int MX = 200005;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> balls(MX);
    rep(i,n) {
        ll x;
        int c;
        cin >> x >> c;
        balls[c].push_back(x);
    }

    vector<vector<ll>> dp(2, vector<ll>(2));
    const vector<vector<ll>> dp_inf(2, vector<ll>(2,LINF));
    rep(i,MX) {
        if (balls[i].size() == 0) continue;
        vector<vector<ll>> now = dp;
        dp = dp_inf;
        sort(balls[i].begin(), balls[i].end());

        rep(j,2) {
            ll l = balls[i][0];
            ll r = balls[i].back();
            ll to_l = abs(now[j][1] - l);
            ll to_r = abs(now[j][1] - r);
            ll m = balls[i].back() - balls[i][0];
            if (chmin(dp[0][0], now[j][0] + to_r + m))
                dp[0][1] = l;
            if (chmin(dp[1][0], now[j][0] + to_l + m))
                dp[1][1] = r;
        }
    }
    ll ans = min(dp[0][0] + abs(dp[0][1]), dp[1][0] + abs(dp[1][1]));
    cout << ans << endl;

    return 0;
}