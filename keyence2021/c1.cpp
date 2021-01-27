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
using P = pair<int,int>;

using mint = modint998244353;
const map<char, int> mp =  {
    {'R', 1},
    {'D', 2},
    {'X', 3}
};

const int MX = 5005;
const mint inv3 = mint(3).inv();
mint dp[MX][MX];

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> grid(h, vector<int>(w));
    rep(i,k) {
        int hi, wi;
        char c;
        cin >> hi >> wi >> c;
        hi--, wi--;
        grid[hi][wi] = mp.at(c);
    }

    dp[0][0] = 1;
    rep(i,h) {
        rep(j,w) {
            mint co = 1;
            if (grid[i][j] == 0) co = inv3 * 2;
            if (grid[i][j] != 1 && i+1 < h) dp[i+1][j] += co * dp[i][j];
            if (grid[i][j] != 2 && j+1 < w) dp[i][j+1] += co * dp[i][j];
        }
    }

    mint ans = dp[h-1][w-1] * mint(3).pow(h*w-k);
    cout << ans.val() << endl;
    return 0;
}