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

int dp[200005][7];

void aoki() {
    cout << "Aoki" << endl;
    exit(0);
}

void takahashi() {
    cout << "Takahashi" << endl;
    exit(0);
}

int main() {
    int n;
    string s, x;
    cin >> n >> s >> x;
    rep(i,7) dp[n][i] = 1;
    dp[n][0] = 0;
    int d = 1;
    for (int i = n-1; 0 <= i; --i) {
        rep(j,7) {
            int r = (j + d*(s[i]-'0')) % 7;
            if (x[i] == 'A') {
                if (dp[i+1][j] == 0 && dp[i+1][r] == 0)
                    dp[i][j] = 0;
                else dp[i][j] = 1;
            }
            else {
                if (dp[i+1][j] == 1 && dp[i+1][r] == 1)
                    dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
        d *= 10;
        d %= 7;
    }
    if (dp[0][0] == 0) takahashi();
    else aoki();
    return 0;
}