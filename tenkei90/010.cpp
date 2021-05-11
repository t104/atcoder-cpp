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
    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(2));
    rep(i,n) {
        int c, p;
        cin >> c >> p;
        --c;
        a[i+1][c] = p;
    }
    rep(i,n) rep(j,2) {
        a[i+1][j] += a[i][j];
    }
    int q;
    cin >> q;
    rep(i,q) {
        int l, r;
        cin >> l >> r;
        --l;
        rep(j,2) {
            cout << a[r][j] - a[l][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}