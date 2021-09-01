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
const int MX = 5010;
mint dp[MX][MX];

void print() {
    rep(i,10) {
        rep(j,10) {
            cout << dp[i][j].val() << ' ';
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<P> ab(n);
    rep(i,n) cin >> ab[i].first;
    rep(i,n) cin >> ab[i].second;
    sort(ab.begin(), ab.end());
    dp[0][0] = 1;
    mint ans = 0;
    rep(i,n) {
        rep(j,MX) {
            auto [a,b] = ab[i];
            dp[i+1][j] += dp[i][j];
            if (b <= j) {
                dp[i+1][j] += dp[i][j-b];
            }
        }
    }
    rep(i,n) {
        for (int j = 1; j <= ab[i].first; ++j) {
            ans += dp[i+1][j];
            ans -= dp[i][j];
        }
    }
    cout << ans.val() << endl;
    // print();

    return 0;
}