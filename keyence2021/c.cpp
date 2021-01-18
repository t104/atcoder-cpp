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
const int MX = 5005;
const map<char, int> mp = {
    {'R', 0},
    {'D', 1},
    {'X', 2}
};

mint dp[MX][MX];
int h, w, k;
const mint inv3 = ((mint) 3).inv();

void printdp() {
    rep(i, h) {
        rep(j,w) {
            cout << dp[i][j].val() << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> h >> w >> k;
    vector<vector<int>> grid(h,vector<int>(w, -1));
    rep(i,k) {
        int hi, wi;
        char ci;
        cin >> hi >> wi >> ci;
        --hi, --wi;
        grid[hi][wi] = mp.at(ci);
    }
    
    dp[0][0] = 1;
    rep(i,h) {
        rep(j,w) {
            int letter = grid[i][j];
            if (letter == 0) {
                if (j+1 < w) {
                    dp[i][j+1] += dp[i][j];
                }
            }
            if (letter == 1) {
                if (i+1 < h) {
                    dp[i+1][j] += dp[i][j];
                }
            }
            if (letter == 2) {
                if (j+1 < w) {
                    dp[i][j+1] += dp[i][j];
                }
                if (i+1 < h) {
                    dp[i+1][j] += dp[i][j];
                }
            }
            if (letter == -1) {
                if (j+1 < w) {
                    dp[i][j+1] += 2*dp[i][j]*inv3;
                }
                if (i+1 < h) {
                    dp[i+1][j] += 2*dp[i][j]*inv3;
                }
            }
        }
    }

    mint ans = ((mint) 3).pow(h*w-k) * dp[h-1][w-1];
    cout << ans.val() << endl;

    return 0;
}