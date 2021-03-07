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
    vector<P> emp(n);
    rep(i,n) cin >> emp[i].first >> emp[i].second;
    int ans = INF;
    rep(i,n) rep(j,n) {
        if (i == j) {
            chmin(ans, emp[i].first + emp[i].second);
        }
        else {
            chmin(ans, max(emp[i].first, emp[j].second));
        }
    }

    cout << ans << endl;

    return 0;
}