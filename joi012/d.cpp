#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const int max_design = 105;
const int max_d = 205;

struct cloth {
    int min, max, design;
    cloth(int min = 0, int max = 0, int design = 0) : min(min), max(max), design(design) {}
};

int dp[max_d][max_design][2];

int main() {
    int d, n;
    cin >> d >> n;
    vector<int> t(d);
    rep(i,d) cin >> t[i];
    vector<cloth> cloths(n);
    rep(i,n) {
        int a, b, c;
        cin >> a >> b >> c;
        cloths[i] = cloth(a, b, c);
    }

    for (auto c : cloths) {
        if (c.min <= t[0] && t[0] <= c.max) {
            dp[0][c.design][0] = 1;
        }
    }
    rep(i,d) {
        for (auto c : cloths) {
            if (c.min <= t[i] && t[i] <= c.max) {
                    dp[i][c.design][0] = 1;
                rep(j, max_design) {
                    if (dp[i-1][j][0] == 1) {
                        chmax(dp[i][c.design][1], dp[i-1][j][1] + abs(c.design - j));
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(i, max_design) {
        chmax(ans, dp[d-1][i][1]);
    }
    cout << ans << endl;
    return 0;
}