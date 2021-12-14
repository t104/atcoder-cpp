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
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    bool ok = true;
    rep(i1, h) {
        rep(j1, w) {
            for (int i2 = i1 + 1; i2 < h; ++i2) {
                for (int j2 = j1 + 1; j2 < w; ++j2) {
                    if (a[i1][j1] + a[i2][j2] > a[i1][j2] + a[i2][j1]) {
                        ok = false;
                    }
                }
            }
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}

