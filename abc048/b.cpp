#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll a, b, x;
    cin >> a >> b >> x;

    ll ans = b/x - a/x;
    if((a % x) == 0) ans++;
    cout << ans << endl;
    return 0;
}