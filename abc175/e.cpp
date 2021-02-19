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

const int MX = 3010;
ll dp[MX][MX][4];

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<ll>> items(h+1, vector<ll>(w+1));
    rep(i,k) {
        int hi, wi, vi;
        cin >> hi >> wi >> vi;
        --hi, --wi;
        items[hi][wi] = vi;
    }

    rep(hi,MX) rep(wi,MX) rep(i,4) dp[hi][wi][i] = -INF;
    dp[0][0][0] = 0;

    rep(hi,h) {
        rep(wi,w) {
            for (int i = 2; 0 <= i; --i) {
                if (0 <= dp[hi][wi][i]) {
                    chmax(dp[hi][wi][i+1], dp[hi][wi][i] + items[hi][wi]);
                }
            }
            rep(i,4) {
                if (0 <= dp[hi][wi][i]) {
                    if (hi+1 < h) {
                        chmax(dp[hi+1][wi][0], dp[hi][wi][i]);
                    }
                    if (wi+1 < w) {
                        chmax(dp[hi][wi+1][i], dp[hi][wi][i]);
                    }
                }
            }
        }
    }

    ll ans = -INF;
    rep(i,4) chmax(ans, dp[h-1][w-1][i]);
    cout << ans << endl;
    return 0;
}