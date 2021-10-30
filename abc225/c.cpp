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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m));
    rep(i,n) rep(j,m) cin >> b[i][j];
    bool ok = true;
    rep(i,n) {
        if (i < n-1 && b[i+1][0] - b[i][0] != 7) {
            ok = false;
        }
        rep(j,m-1) {
            if (b[i][j+1] - b[i][j] != 1) {
                ok = false;
            }
            if (j+1 == m-1 && b[i][j+1] % 7 == 0) {
                continue;
            }
            if ((b[i][j] % 7) == 0) {
                ok = false;
            }
            if ((b[i][j+1] % 7) - (b[i][j] % 7) != 1) {
                ok = false;
            }
        }
    }
    cout << (ok ? "Yes": "No") << endl;
    return 0;
}

