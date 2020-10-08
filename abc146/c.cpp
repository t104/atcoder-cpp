#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

ll N_MAX = 1e9;

int main() {
    ll a,b,x;
    cin >> a >> b >> x;
    if (x < a) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    int d = 0;
    rep(i,10) {
        ll xi = a;
        rep(j,i) xi *= 10;
        xi += b*i;
        if (x < xi) break;
        d = i+1;
    }
    x -= b*d;
    cout << min(x/a, N_MAX) << endl;
    
    return 0;
}