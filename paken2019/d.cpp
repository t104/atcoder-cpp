#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const map<char, int> cols = {{'R', 0}, {'B', 1}, {'W',2}, {'#', 3}};

int main() {
    int n;
    cin >> n;
    vector<string> s(5);
    rep(i,5) cin >> s[i];
    vector<vector<int>> dp(n+1, vector<int>(3, INF));
    rep(i,3) dp[0][i] = 0;
    rep(i,n) {
        vector<int> color(4);
        rep(j,5) {
            color.at(cols.at(s[j][i]))++;
        }
        rep(j,3) {
            chmin(dp[i+1][j], dp[i][(j+1)%3] + 5 - color[j]);
            chmin(dp[i+1][j], dp[i][(j+2)%3] + 5 - color[j]);
        }
    }
    int ans = INF;
    rep(i,3) chmin(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}