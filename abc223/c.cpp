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
    cout << std::fixed << std::setprecision(15);
    vector<int> a(n), b(n);
    rep(i,n) {
        cin >> a[i] >> b[i];
    }
    vector<double> l(n+1), r(n+1);
    rep(i,n) {
        l[i+1] = l[i] + (double) a[i] / b[i];
        r[n-1-i] = r[n-i] + (double) a[n-1-i] / b[n-1-i];
    }
    rep(i,n) {
        if (l[i+1] < r[i+1]) continue;
        double ans = 0;
        rep(j,i) ans += a[j];
        ans += (a[i] - (double) (l[i] - r[i+1]) * b[i]) / 2;
        cout << ans << endl;
        return 0;
    }
    return 0;
}

