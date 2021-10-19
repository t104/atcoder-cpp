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

using mint = modint1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(m);
    rep(i,n) cin >> x[i];
    rep(i,m) cin >> y[i];
    mint h = 0, w = 0;
    rep(i,n-1) {
        mint l = x[i+1] - x[i];
        w += l * mint(i+1) * mint(n-1-i);
    }
    rep(i,m-1) {
        mint l = y[i+1] - y[i];
        h += l * mint(i+1) * mint(m-1-i);
    }
    mint ans = h * w;
    cout << ans.val() << endl;
    return 0;
}