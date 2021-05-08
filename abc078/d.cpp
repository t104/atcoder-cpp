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
    ll z, w;
    cin >> n >> z >> w;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    if (n == 1) {
        cout << abs(w-a[0]) << endl;
        return 0;
    }

    cout << max(abs(w-a.back()), abs(a.back() - a[n-2])) << endl;
    return 0;
}