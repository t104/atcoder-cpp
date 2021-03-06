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

const int MX = 410;
int dp[MX][MX];

int main() {
    int n;
    cin >> n;
    int N = n*2;
    vector<int> a(MX);
    rep(i,N) cin >> a[i];
    
    rep(i,N) {
        for (int j = i; j <= N; ++j) dp[i][j] = INF;
        dp[i][i] = 0;
    }


    for (int w = 2; w <= N; w += 2) {
        for (int l = 0; l+w <= N; ++l) {
            int r = l+w;
            for (int m = l+1; m < r; ++m) {
                chmin(dp[l][r], dp[l][m] + dp[m][r]);
                chmin(dp[l][r], dp[l+1][r-1] + abs(a[l] - a[r-1]));
            }
        }
    }

    cout << dp[0][N] << endl;
    
    return 0;
}