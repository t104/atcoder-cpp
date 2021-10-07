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
    ll n;
    cin >> n;
    vector<int> a;
    while (n) {
        a.push_back(n%10);
        n /= 10;
    }
    int sz = a.size();
    ll ans = 0;
    rep(i, 1<<sz) {
        vector<int> x, y;
        rep(j, sz) {
            if ((i>>j)&1) {
                x.push_back(a[j]);
            } else {
                y.push_back(a[j]);
            }
        }
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        ll X = 0, Y = 0;
        for (auto xi: x) {
            X *= 10;
            X += xi;
        }
        for (auto yi: y) {
            Y *= 10;
            Y += yi;
        }
        chmax(ans, X*Y);
    }
    cout << ans << endl;
    return 0;
}

