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
    vector<vector<int>> d(n+1, vector<int>(n+1));
    rep(i,n) rep(j,n) cin >> d[i+1][j+1];
    rep(i,n) rep(j,n) d[i+1][j+1] += d[i+1][j] + d[i][j+1] - d[i][j];
    
    vector<int> mx(n*n+1);
    for (int h = 0; h <= n; ++h) {
        for (int w = 0; w <= n; ++w) {
            for (int i = 0; i+h <= n; ++i) {
                for (int j = 0; j+w <= n; ++j) {
                    chmax(mx[h*w], d[i+h][j+w] - d[i+h][j] - d[i][j+w] + d[i][j]);
                }
            }
        }
    }
    rep(i,n*n) chmax(mx[i+1], mx[i]);

    int q;
    cin >> q;
    rep(i,q) {
        int p;
        cin >> p;
        cout << mx[p] << endl;
    }
    return 0;
}