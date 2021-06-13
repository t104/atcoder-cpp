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

const double PI = acos(-1);

int main() {
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    
    double ans = 0.;
    auto degree = [&](double x, double y) {
        double res = abs(x-y);
        return PI < res ? 2*PI - res : res;
    };
    rep(i,n) {
        vector<double> th;
        rep(j,n) {
            if (i == j) continue;
            double xi = x[j] - x[i];
            double yi = y[j] - y[i];
            th.push_back(atan2(yi, xi));
        }
        sort(th.begin(), th.end());
        for (auto ti: th) {
            int idx = lower_bound(th.begin(), th.end(), -PI + ti) - th.begin();
            if (idx < th.size()) chmax(ans, degree(th[idx], ti));
            if (0 <= idx-1) chmax(ans, degree(th[idx-1], ti));
        }
    }

    cout << std::fixed << std::setprecision(15);
    cout << ans * 180 / PI << endl;
    return 0;
}