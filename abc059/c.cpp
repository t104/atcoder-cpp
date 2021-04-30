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
    ll a1 = 0, a2 = 0, s1 = 0, s2 = 0;
    rep(i,n) {
        s1 += a[i];
        if (i%2 == 0) {
            if (s1 <= 0) {
                a1 += 1-s1;
                s1 = 1;
            }
        }
        else {
            if (0 <= s1) {
                a1 += s1+1;
                s1 = -1;
            }
        }
    }
    rep(i,n) {
        s2 += a[i];
        if (i%2 == 0) {
            if (0 <= s2) {
                a2 += s2+1;
                s2 = -1;
            }
        }
        else {
            if (s2 <= 0) {
                a2 += 1-s2;
                s2 = 1;
            }
        }
    }
    cout << min(a1,a2) << endl;
    return 0;
}