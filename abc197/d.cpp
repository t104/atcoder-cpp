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
using P = pair<double,double>;

const double PI = acos(-1);

P rotate(double x, double y, double s) {
    return {cos(s)*x - sin(s)*y, sin(s)*x + cos(s)*y};
}

int main() {
    cout << std::fixed << std::setprecision(15);
    int n;
    cin >> n;
    double x0, y0, xn, yn;
    cin >> x0 >> y0 >> xn >> yn;
    double xm = (x0+xn)/2;
    double ym = (y0+yn)/2;
    auto [xr, yr] = rotate(x0-xm, y0-ym, 2*PI/double(n));
    xr += xm;
    yr += ym;
    cout << xr << endl;
    cout << yr << endl;
    return 0;
}