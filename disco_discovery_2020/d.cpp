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


int main() {
    int m;
    cin >> m;
    vector<ll> d(m);
    vector<ll> c(m);
    rep(i,m) cin >> d[i] >> c[i];

    ll D = 0, S = 0;
    rep(i,m) {
        D += c[i];
        S += d[i] * c[i];
    }
    cout << (D-1) + (S-1)/9 << endl;

    return 0;
}