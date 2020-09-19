#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;

    if (2 * n < k) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    int ks = n / k;
    ans += (ll) ks * ks * ks;
    if (k % 2 == 0) {
        int rs = (n - k / 2) / k + 1;
        ans += (ll) rs * rs * rs;
    }
    cout << ans << endl;
    return 0;
}