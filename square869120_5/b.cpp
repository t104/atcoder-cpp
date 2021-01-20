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
using P = pair<int,int>;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
    cout << std::fixed << std::setprecision(15);

    int n, m;
    cin >> n >> m;
    vector<int> x(n+m), y(n+m), r(n);
    rep(i,n) {
        cin >> x[i] >> y[i] >> r[i];
    }
    rep(i,m) {
        cin >> x[n+i] >> y[n+i];
    }

    vector<vector<double>> d(n+m, vector<double>(n+m));
    rep(i,n+m) {
        rep(j,n+m) {
            d[i][j] = distance(x[i], y[i], x[j], y[j]);
        }
    }

    double ans = INF;

    rep(i,n) {
        chmin(ans, r[i]);
    }

    rep(i,n) {
        rep(j,m) {
            chmin(ans, d[i][n+j] - r[i]);
        }
    }

    rep(i,m) {
        for (int j = i+1; j < m; ++j) {
            chmin(ans, d[n+i][n+j]/2);
        }
    }

    cout << ans << endl;
    return 0;
}