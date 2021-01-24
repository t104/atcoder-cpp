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
using P = pair<double,double>;

struct L {
    double a, b;
    L(double a=0, double b=0):a(a),b(b) {}
    L operator+(const L& x) const {
        return L(a+x.a, b+x.b);
    }
    L operator-(const L& x) const {
        return L(a-x.a, b-x.b);
    }
    L operator/(int x) const {
        return L(a/x, b/x);
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> f(n+1);
    rep(i,k) {
        int p;
        cin >> p;
        f[p] = 1;
    }

    vector<L> dp(n+1);
    L s;
    for (int i = n-1; 0 <= i; --i) {
        // L(1,0) -> x (a=1, b=0)
        if (f[i]) dp[i] = L(1,0);
        else dp[i] = s/m + L(0,1);
        s = s+dp[i];
        if (i+m <= n) s = s - dp[i+m];
    }
    double a = dp[0].a, b = dp[0].b;
    if (1 < a+1e-6) {
        cout << -1 << endl;
        return 0;
    }
    cout << std::fixed << std::setprecision(15);
    cout << b/(1-a) << endl;
    return 0;
}