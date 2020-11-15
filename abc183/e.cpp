#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using mint = modint1000000007;

int h, w;

void print(vector<vector<mint>> &grid) {
    rep(i,h+1) {
        rep(j, w+1) {
            cout << grid.at(i).at(j).val() << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s.at(i);
    vector<vector<mint>>
    dp(h+1, vector<mint>(w+1)),
    l(h+1, vector<mint>(w+1)),
    u(h+1, vector<mint>(w+1)),
    ul(h+1, vector<mint>(w+1));


    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (i == 1 && j == 1) {
                dp[i][j] = 1;
                continue;
            }
            if (s[i-1][j-1] == '#') continue;
            l[i][j] = dp[i][j-1] + l[i][j-1];
            u[i][j] = dp[i-1][j] + u[i-1][j];
            ul[i][j] = dp[i-1][j-1] + ul[i-1][j-1];
            dp[i][j] = l[i][j] + u[i][j] + ul[i][j];
        }
    }

    cout << dp[h][w].val() << endl;
    return 0;
}