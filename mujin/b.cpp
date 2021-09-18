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
    double a, b, c;
    cin >> a >> b >> c;
    double mx = a + b + c;
    double mi = max(0., 2*max({a, b, c}) - mx);
    double ans = (mx*mx - mi*mi) *PI;
    cout << std::fixed << std::setprecision(15);
    cout << ans << endl;
    return 0;
}

