#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    ll x;
    cin >> x;
    ll ans = (ll) x/11;
    ans *= 2;
    x %= 11;
    if (0 < x) {
        ans++;
        x -= 6;
    }
    if (0 < x) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}