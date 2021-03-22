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

int n, x, y;

double distance(int x1, int y1, int x2, int y2) {
    if (x2-x1 == 0) {
        return abs(x-x1);
    }
    double a = double(y2-y1)/double(x2-x1);
    double c = double(-a*x1+y1);
    return abs((a*x)-y+c)/sqrt(a*a+1);
}

int main() {
    cout << std::fixed << std::setprecision(15);
    cin >> x >> y >> n;
    vector<int> X(n), Y(n);
    rep(i,n) cin >> X[i] >> Y[i];
    double ans = 1e9;
    rep(i,n) {
        double d = distance(X[i], Y[i], X[(i+1)%n], Y[(i+1)%n]);
        // cout << d << endl;
        chmin(ans, d);
    }
    cout << ans << endl;
    return 0;
}