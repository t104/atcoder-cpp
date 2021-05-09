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

ll dp[4][3000100];

void printdp(int len) {
    rep(j,len) {
        rep(i,4) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    ll n, k;
    cin >> n >> k;
    dp[0][0] = 1;

    rep(i,3) {
        rep(j,3*n+1) dp[i][j+1] += dp[i][j];
        rep(j,3*n+1) {
            if (0 <= j-1)
                dp[i+1][j] += dp[i][j-1];
            if (0 <= j-n-1)
                dp[i+1][j] -= dp[i][j-n-1];
        }
    }

    // printdp(3*n+1);

    ll sum = 0;
    rep(i,3*n+1) {
        if (dp[3][i] < k) {
            k -= dp[3][i];
        }
        else {
            sum = i;
            break;
        }
    }

    for (int x = max(1LL, sum-2*n); x <= min(n, sum-2); ++x) {
        int d = min(n, sum-x-1) - max(1LL, sum-x-n) + 1;
        if (d < k) {
            k -= d;
            continue;
        }
        for (int y = max(1LL, sum-x-n); y <= min(n, sum-x-1); ++y) {
            k--;
            if (k == 0) {
                printf("%d %d %d\n", x, y, sum-x-y);
                return 0;
            }
        }
    }
    return 0;
}