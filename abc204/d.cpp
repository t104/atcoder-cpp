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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int sum = 0;
    rep(i,n) sum += a[i];
    vector<int> dp(sum+1);
    dp[sum] = 1;
    rep(i,n) {
        rep(s, sum+1) {
            if (0 <= s - a[i]) {
                dp[s-a[i]] += dp[s];
            }
        }
    }
    int ans = sum;
    rep(i, sum+1) {
        if (dp[i]) {
            chmin(ans, max(i,sum-i));
        }
    }
    cout << ans << endl;
    return 0;
}