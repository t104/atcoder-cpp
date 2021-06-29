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

using mint = modint1000000007;

mint dp[10][1<<10];

int main() {
    int h, w;
    cin >> h >> w;
    assert(h < 10 && w < 10);
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(flg, 1<<w) {
        bool ok = true;
        rep(i,w) {
            if (flg>>i&1) {
                if (s[0][i] == '#') {
                    ok = false;
                    continue;
                }
                if (i+1 < w && flg>>(i+1)&1) {
                    ok = false;
                    continue;
                }
            }
        }
        if (ok) dp[0][flg] = 1;
    }
    rep(i,h-1) {
        rep(flg1, 1<<w) {
            rep(flg2, 1<<w) {
                bool ok = true;
                rep(j,w) {
                    if (flg2>>j&1) {
                        if (s[i+1][j] == '#' ||
                            (j+1 < w && flg2>>(j+1)&1) ||
                            (j+1 < w && flg1>>(j+1)&1) ||
                            flg1>>j&1 ||
                            (0 <= j-1 && flg1>>(j-1)&1)
                        ) {
                            ok = false;
                            continue;
                        }
                    }
                }
                if (ok) dp[i+1][flg2] += dp[i][flg1];
            }
        }
    }
    mint ans = 0;
    rep(flg, 1<<w) {
        ans += dp[h-1][flg];
    }
    cout << ans.val() << endl;
    return 0;
}