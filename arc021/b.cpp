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
    vector<ll> a(n), b(n);
    rep(i,n) cin >> b[i];
    rep(i,n-1) {
        rep(j, 32) {
            if ((b[i] >> j)&1) {
                a[i+1] |= ~a[i] & (1LL << j);
            } else {
                a[i+1] |= a[i] & (1LL << j);
            }
        }
    }
    if ((a[n-1] ^ a[0]) != b[n-1]) {
        cout << -1 << endl;
        return 0;
    }
    rep(i,n) cout << a[i] << endl;
    return 0;
}

