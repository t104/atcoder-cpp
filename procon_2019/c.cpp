#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int k, a, b;
    cin >> k >> a >> b;
    ll ans = 1;
    if (b-a <= 2 || k <= a) {
        cout << ans + k << endl;
        return 0;
    }
    k -= a+1;
    ans = b;
    int q = k/2;
    int r = k%2;
    ans += (ll) q * (b-a);
    ans += r;
    cout << ans << endl;
    return 0;
}