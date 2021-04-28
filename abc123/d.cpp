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
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    vector<ll> ab;
    rep(i,x) rep(j,y) ab.push_back(a[i]+b[j]);
    sort(ab.rbegin(), ab.rend());
    sort(c.rbegin(), c.rend());
    vector<ll> abc;
    rep(i,min(k,x*y)) {
        rep(j,z) {
            abc.push_back(ab[i]+c[j]);
        }
    }
    sort(abc.rbegin(), abc.rend());
    rep(i,k) cout << abc[i] << endl;
    return 0;
}