#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int max_n = 3000;
ll dp[max_n][max_n];

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    
    rep(i,n) {
        if (n%2 == 0) dp[0][i] = -a.at(i);
        else dp[0][i] = a.at(i);
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; i + j < n; ++j) {
            if ((n-i)%2 == 0) {
                dp[i][j] = min(dp[i-1][j+1] - a[j], dp[i-1][j] - a[i+j]);
            }
            else {
                dp[i][j] = max(dp[i-1][j+1] + a[j], dp[i-1][j] + a[i+j]);
            }
        }
    }

    cout << dp[n-1][0] << endl;
    return 0;
}