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
    cout << std::fixed << std::setprecision(15);
    int n;
    cin >> n;
    vector<double> a(n);
    rep(i,n) cin >> a[i];

    auto f = [&](double x) {
        double res = 0.;
        rep(i,n) {
            res += x + a[i] - min(a[i], 2. * x);
        }
        return res;
    };

    double l = 0.;
    double r = 1e9;
    int cnt = 100;
    while (cnt--) {
        double m1 = (l * 2 + r) / 3;
        double m2 = (l + 2 * r) / 3;
        if (f(m2) < f(m1)) l = m1;
        else r = m2;
    }
    
    cout << f(l) / n << endl;
    return 0;
}