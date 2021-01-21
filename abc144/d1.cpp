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

const double PI = acos(-1);

int main() {
    cout << std::fixed << std::setprecision(15);
    double a, b, x;
    cin >> a >> b >> x;
    double total = a*a*b;
    double ans = 0.;
    if (x*2 < total) {
        ans = atan(a*b*b/(2*x));
    }
    else {
        ans = atan((2*(total-x))/(a*a*a));
    }
    cout << 360 * (ans/(2*PI)) << endl;
    return 0;
}