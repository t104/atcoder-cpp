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

const int mx = 100;
string fmt = ".#";

int main() {
    int a, b;
    cin >> a >> b;

    vector<vector<int>> grid(mx, vector<int>(mx));
    for (int i = mx/2; i < mx; ++i) rep(j,mx) {
        grid[i][j] = 1;
    }

    --a, --b;
    for (int i = 0; i < mx/2; i += 2) {
        for (int j = 0; j < mx; j += 2) {
            if (b == 0) break;
            grid[i][j] = 1;
            --b;
        }
    }

    for (int i = mx/2 + 1; i < mx; i += 2) {
        for (int j = 0; j < mx; j += 2) {
            if (a == 0) break;
            grid[i][j] = 0;
            --a;
        }
    }

    cout << mx << ' ' << mx << endl;
    rep(i,mx) {
        string s;
        rep(j,mx) {
            s.push_back(fmt[grid[i][j]]);
        }
        cout << s << endl;
    }
    return 0;
}