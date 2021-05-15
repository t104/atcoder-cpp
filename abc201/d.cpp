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

int t(int i, int j);
int a(int i, int j);
int h, w;
vector<vector<int>> grid;
vector<vector<int>> dp;

int t(int i, int j) {
    if (-INF/2 <= dp[i][j]) return dp[i][j];
    int res = -INF;
    if (i+1 < h) {
        chmax(res, a(i+1, j));
    }
    if (j+1 < w) chmax(res, a(i, j+1));
    if (res == -INF) res = 0;
    if (i == 0 && j == 0) return dp[i][j] = res;
    return dp[i][j] = res + grid[i][j];
}

int a(int i, int j) {
    if (-INF/2 <= dp[i][j]) return dp[i][j];
    int res = INF;
    if (i+1 < h) chmin(res, t(i+1, j));
    if (j+1 < w) chmin(res, t(i, j+1));
    if (res == INF) res = 0;
    return dp[i][j] = res + grid[i][j];
}

int main() {
    cin >> h >> w;
    grid.resize(h, vector<int>(w));
    dp.resize(h, vector<int>(w, -INF));
    rep(i,h) {
        string s;
        cin >> s;
        rep(j,w) {
            if ((i+j)%2 == 0) {
                if (s[j] == '+') grid[i][j] = -1;
                else grid[i][j] = 1;
            }
            else {
                if (s[j] == '+') grid[i][j] = 1;
                else grid[i][j] = -1;
            }
        }
    }
    int p = t(0,0);
    if (p == 0) cout << "Draw" << endl;
    else if (0 < p) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}