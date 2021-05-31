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

void print_dp(vector<mint> &dp) {
    rep(i,235) {
        cout << dp[i].val() << ' ';
    }
    cout << endl;
} 

int main() {
    int k;
    cin >> k;
    if (k%9 != 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<mint> dp(100010);
    dp[0] = 1;
    mint ans = 0;
    rep(i,k+1) {
        for (int d = 1; d <= 9; ++d) {
            if (i-d < 0) break;
            dp[i] += dp[i-d];
        }
        ans += dp[k];
    }
    cout << dp[k].val() << endl;
    return 0;
}