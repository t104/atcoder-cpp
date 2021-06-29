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

mint dp[18*18][1<<20];

int main() {
    int h, w;
    cin >> h >> w;
    assert(h < 18 && w < 18);
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    dp[0][0] = 1;
    if (s[0][0] == '.') dp[0][1<<w] = 1;
    rep(i,h) {
        rep(j,w) {
            rep(flg1, 1<<(w+1)) {
                int flg2 = flg1>>1;
                int pos = i*w+j;
                if (h*w <= pos+1) break;
                int nh = (pos+1)/w;
                int nw = (pos+1)%w;
                dp[pos+1][flg2] += dp[pos][flg1];
                int mask = 0;
                if (0 <= nh-1 && 0 <= nw-1) mask |= 1;
                if (0 <= nh-1) mask |= 1<<1;
                if (0 <= nh-1 && nw+1 < w) mask |= 1<<2;
                if (0 <= nw-1) mask |= 1<<w;
                if (s[nh][nw] == '.' && (flg1 & mask) == 0) {
                    dp[pos+1][flg2|(1<<w)] += dp[pos][flg1];
                }
            }
        }
    }
    mint ans = 0;
    rep(i, 1<<(w+1)) {
        ans += dp[h*w-1][i];
    }
    cout << ans.val() << endl;
    return 0;
}