#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const int MX = 21;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    vector<vector<ll>> dp(n, vector<ll> (MX));
    dp[0][0] = 1;
    rep(i,n-1) {
        rep(j,MX) {
            if (a[i] <= j) {
                dp[i+1][j] += dp[i][j - a[i]];
            }
            if (0 < i && j + a[i] < MX) {
                dp[i+1][j] += dp[i][j + a[i]];
            }
        }
    }
    cout << dp[n-1][a[n-1]] << endl;
    return 0;
}