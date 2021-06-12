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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> g(h, vector<int>(w));
    rep(i,h) rep(j,w) cin >> g[i][j];

    int ans = 0;
    rep(s, 1<<h) {
        map<int,int> mp;
        rep(wi, w) {
            int a = -1;
            bool ok = true;
            rep(hi, h) {
                if ((s>>hi)&1) {
                    if (a == -1) a = g[hi][wi];
                    if (a != g[hi][wi]) ok = false;
                }
            }
            if(ok) mp[a] += __builtin_popcount(s);
        }
        for (auto p: mp) {
            chmax(ans, p.second);
        }
    }
    cout << ans << endl;
    return 0;
}