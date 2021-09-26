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
    string s;
    cin >> n >> s;
    int lcm = 0;
    for (int m = 1; m < n; ++m) {
        string s1 = s.substr(0, m);
        string s2 = s.substr(m, n - m);
        int sz1 = s1.size();
        int sz2 = s2.size();
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1));
        rep(i, sz1) {
            rep(j, sz2) {
                chmax(dp[i+1][j+1], dp[i][j+1]);
                chmax(dp[i+1][j+1], dp[i+1][j]);
                if (s1[i] == s2[j]) chmax(dp[i+1][j+1], dp[i][j] + 1);
            }
        }
        chmax(lcm, dp[sz1][sz2]);
    }
    cout << n - lcm * 2 << endl;
    return 0;
}