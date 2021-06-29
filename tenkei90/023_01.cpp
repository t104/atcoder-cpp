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
    assert(h <= 4 && w <= 4);
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;
    rep(flg, 1<<(h*w)) {
        bool ok = true;
        rep(i,h) {
            rep(j,w) {
                if (flg>>(i*w+j)&1) {
                    if (s[i][j] == '#') ok = false;
                    if (j+1 < w && flg>>(i*w+j+1)&1) ok = false;
                    if (i+1 < h && flg>>((i+1)*w+j)&1) ok = false;
                    if (i+1 < h && j+1 < w && flg>>((i+1)*w+j+1)&1) ok = false;
                    if (0 <= i-1 && j+1 < w && flg>>((i-1)*w+j+1)&1) ok = false;
                }
            }
        }
        if (ok) {
            // cout << bitset<16>(flg) << endl;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}