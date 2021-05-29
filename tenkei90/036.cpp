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
    int n, q;
    cin >> n >> q;
    vector<ll> x(n), y(n);
    rep(i,n) {
        ll xi, yi;
        cin >> xi >> yi;
        x[i] = xi-yi;
        y[i] = xi+yi;
    }
    ll mix = *min_element(x.begin(), x.end());
    ll mxx = *max_element(x.begin(), x.end());
    ll miy = *min_element(y.begin(), y.end());
    ll mxy = *max_element(y.begin(), y.end());
    rep(i,q) {
        int ind;
        cin >> ind;
        ind--;
        cout << max({abs(x[ind]-mix), abs(x[ind]-mxx), abs(y[ind]-miy), abs(y[ind]-mxy)}) << endl;
    }
    return 0;
}