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
    
    ll low = -INF, high = INF;
    ll add = 0;
    rep(i,n) {
        ll a, t;
        cin >> a >> t;
        if (t == 1) {
            low += a;
            high += a;
            add += a;
        }

        if (t == 2) {
            chmax(low, a);
            chmax(high, a);
        }

        if (t == 3) {
            chmin(low, a);
            chmin(high, a);
        }
    }

    int q;
    cin >> q;
    rep(i,q) {
        ll x;
        cin >> x;
        cout << min(max(x+add, low), high) << endl;
    }

    return 0;
}