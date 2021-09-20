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
    vector<vector<int>> b(n, vector<int>(m)), a(n, vector<int>(m));
    rep(i,n) {
        string s;
        cin >> s;
        rep(j,m) b[i][j] = s[j] - '0';
    }
    rep(i,n-1) {
        rep(j,m) {
            a[i+1][j] += b[i][j];
        }
        rep(j,m) {
            b[i][j] -= a[i+1][j];
            if (i+2 < n) b[i+2][j] -= a[i+1][j];
            if (0 <= j-1) b[i+1][j-1] -= a[i+1][j];
            if (j+1 < m) b[i+1][j+1] -= a[i+1][j];
        }
    }
    rep(i,n) {
        rep(j,m) cout << a[i][j];
        cout << endl;
    }
    return 0;
}

