#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    ans += (n/(a+b)) *a;
    ll r = n%(a+b);
    if(r > a) ans += a;
    else ans += r;
    cout << ans << endl;
    return 0;
}