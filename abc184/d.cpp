#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

long double dp[105][105][105];

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << std::fixed << std::setprecision(15);

    // rep(i,101) rep(j,101) {
    //     dp[100][i][j] = 1;
    //     dp[i][j][100] = 1;
    //     dp[i][100][j] = 1;
    // }

    for (int i = 99; 0 <= i; --i) {
        for (int j = 99; 0 <= j; --j) {
            for (int k = 99; 0 <= k; --k) {
                int s = i+j+k;
                dp[i][j][k] += (long double) i/s * (1 + dp[i+1][j][k]);
                dp[i][j][k] += (long double) j/s * (1 + dp[i][j+1][k]);
                dp[i][j][k] += (long double) k/s * (1 + dp[i][j][k+1]);
            }
        }
    }

    
    cout << dp[a][b][c] << endl;
    return 0;
}