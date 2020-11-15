#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n) rep(j,n) cin >> a.at(i).at(j);
    
    vector<mint> dp(1<<n);
    dp.at(0) = 1;
    // s : ペアになっている女性の集合
    for (int s = 0; s < (1<<n); ++s) {
        // ペアになっている男性の人数
        int i = __builtin_popcount(s);

        rep(j,n) {
            // j 番目の女性がペアになっている
            // AND
            // i-1 番目 (0 から i-1 番目までで i 人) の男性と j 番目の女性がペアになることができる
            if ((s>>j)&1 && a[i-1][j] == 1) {
                // cout << bitset<8>(s) << ' ' << bitset<8>(s^(1<<j)) << ' ' << j << endl;
                // 集合 s に集合 s から j 番目の女性がペアになっていない場合の数を足す
                dp[s] += dp[s ^ (1<<j)];
            }
        }

    }

    cout << dp[(1<<n) - 1].val() << endl;
    return 0;
}