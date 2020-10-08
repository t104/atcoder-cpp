#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    ll n, p;
    cin >> n >> p;
    ll ans = 1;
    if (n == 1) {
        cout << p << endl;
        return 0;
    }
    for (ll i = 2;;++i) {
        ll k = 1;
        rep(j,n) {
            k *= i;
            if (p < k) break;
        }
        if (p < k) break;
        if (p % k == 0) chmax(ans, i);
    }
    cout << ans << endl;
    return 0;
}