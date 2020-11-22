#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    char aa, ab, ba ,bb;
    cin >> aa >> ab >> ba >> bb;
    
    if ((ab == 'A' && aa == 'A')||(ab == 'B' && bb == 'B')) {
        cout << 1 << endl;
        return 0;
    }
    
    if (ab == ba) {
        vector<vector<mint>> dp(n, vector<mint>(2));
        dp[0][0] = 1;
        dp[0][1] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
            dp[i][1] = dp[i-1][0];
        }
        cout << dp[n-1][1].val() << endl;
        // rep(i,n) {
        //     cout << dp[i][0].val() << ' ' << dp[i][1].val() << endl;
        // }
        return 0;
    }

    mint ans = 1;
    if (3 < n) ans *= mint(2).pow(n-3);
    cout << ans.val() << endl;
    return 0;
}