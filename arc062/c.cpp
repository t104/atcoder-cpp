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
    vector<int> t(n), a(n);
    rep(i,n) cin >> t[i] >> a[i];
    ll tk = 1, ak = 1;
    rep(i,n) {
        ll ntk = tk / t[i] * t[i];
        if (tk%t[i]) ntk += t[i];
        ll nak = ntk/t[i]*a[i];
        if (nak < ak) {
            nak = ak/a[i]*a[i];
            if (ak%a[i]) nak += a[i];
            ntk = nak/a[i]*t[i];
        }
        tk = ntk;
        ak = nak;
    }
    cout << tk + ak << endl;
    return 0;
}