#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a.at(i);
    ll sum = 0;
    rep(i, n) sum += a.at(i);
    ll x = 0;
    int k = 0;
    rep(i, n) {
        x += a.at(i);
        if (sum - 2 * x < 0) {
            k = i;
            break;
        }
    }
    ll ans = x - (sum - x);
    x -= a.at(k);
    ans = min(ans, abs(x - (sum - x)));
    cout << ans << endl;
    return 0;
}