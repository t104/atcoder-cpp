#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
double p;

double df(double x) {
    return 1 + p * (pow(2, -2./3. * x) * (-2./3. * log(2)));
}

double f(double x) {
    return x + p * pow(2, -2./3. * x);
}

int main() {
    cout << std::fixed << std::setprecision(15);
    cin >> p;
    double l = -1e18, r = 1e18;
    double x = 0.;
    rep(i,10000) {
        double mid = (l+r) / 2;
        if (0 < df(mid)) {
            r = mid;
            x = mid;
        }
        else {
            l = mid;
            x = mid;
        }
    }
    // cout << df(x) << endl;
    if (x < 0) {
        cout << f(0) << endl;
        return 0;
    }
    cout << f(x) << endl;
    return 0;
}