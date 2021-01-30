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
using P = pair<int,int>;

int n;
const int MX = 55;


int main() {
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    rep(i,2) rep(j,n) cin >> a[j][i];
    for (int i = 1; i < n; i+=2) {
        swap(a[i][0], a[i][1]);
    }

    vector<vector<int>> dp(1<<n, vector<int>(MX, INF));
    dp[0][0] = 0;
    rep(i,1<<n) {
        vector<P> ords;
        int x = __builtin_popcount(i);
        int itr = x;
        rep(j,n) {
            if (!((i>>j)&1))
                ords.emplace_back(j, itr++);
        }

        rep(j,MX) {
            if (INF <= dp[i][j]) continue;
            for (auto p : ords) {
                int r = a[p.first][p.first%2];
                rep(k,r+1) {
                    chmin(dp[i|(1<<p.first)][r], dp[i][k] + abs(p.second - x));
                }
            }
        }
    }

    int ans = INF;
    rep(i,MX) chmin(ans, dp[(1<<n) - 1][i]);
    if (INF <= ans) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}