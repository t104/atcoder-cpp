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

ll dp[105][4][2];

int main() {
    string S;
    int K;
    cin >> S >> K;
    int n = S.size();
    dp[0][0][0] = 1;
    rep(i,n) rep(j,4) rep(k,2) {
        int nd = S[i] - '0';
        rep(d, 10) {
            int ni = i+1, nj = j, nk = k;
            if (d != 0) nj++;
            if (K < nj) continue;
            if (k == 0) {
                if (nd < d) continue;
                if (d < nd) nk = 1; 
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    cout << dp[n][K][0] + dp[n][K][1] << endl;
    return 0;
}