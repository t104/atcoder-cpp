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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    int p = 0, q = 0;
    rep(i,n) if (a[i] < 0) q++;
    p = n-q;
    if (p == 0) p++, q--;
    if (q == 0) p--, q++;
    vector<ll> x, y;
    for (int i = q; i < n-1; ++i) {
        x.push_back(a[0]);
        y.push_back(a[i]);
        a[0] -= a[i];
    }
    rep(i,q) {
        x.push_back(a[n-1]);
        y.push_back(a[i]);
        a[n-1] -= a[i];
    }
    cout << a[n-1] << endl;
    rep(i,n-1) {
        printf("%ld %ld\n", x[i], y[i]);
    }
    return 0;
}