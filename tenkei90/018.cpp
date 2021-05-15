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

ll T, L, X, Y;

const double PI = acos(-1);

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
}

double solve(ll e) {
    e %= T;
    if (e == 0) return 0.;
    double th = double(e) / double(T) * 2. * PI;
    double y = (double) -L/2*sin(th);
    double z = (double) L/2 - (double) L/2*cos(th);
    double d = distance(X, Y, 0, 0, y, z);
    double res = asin(z/d);
    return res * 180 / PI;
}

int main() {
    int q;
    cin >> T >> L >> X >> Y >> q;
    
    cout << std::fixed << std::setprecision(15);
    rep(i,q) {
        ll e;
        cin >> e;
        cout << solve(e) << endl;
    }
    return 0;
}