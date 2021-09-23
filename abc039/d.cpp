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

int h, w;

int main() {
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    vector<vector<int>> ans(h, vector<int>(w)), shrink(h, vector<int>(w));
    bool possible = true;
    rep(i,h) {
        rep(j,w) {
            int color = 1;
            for (int k = i-1; k <= i+1; ++k) {
                for (int l = j-1; l <= j+1; ++l) {
                    if (in(k, 0, h) && in(l, 0, w) && a[k][l] == '.') {
                        color = 0;
                    }
                }
            }
            ans[i][j] = color;
            if (color == 1) {
                for (int k = i-1; k <= i+1; ++k) {
                    for (int l = j-1; l <= j+1; ++l) {
                        if (in(k, 0, h) && in(l, 0, w)) {
                            shrink[k][l] = 1;
                        }
                    }
                }
            }
        }
    }

    rep(i,h) rep(j,w) {
        if (a[i][j] == '#' && shrink[i][j] == 0) {
            possible = false;
        }
    }

    if (possible) {
        cout << "possible" << endl;
        rep(i,h) {
            rep(j,w) {
                cout << (ans[i][j] ? '#' : '.');
            }
            cout << endl;
        }
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}

