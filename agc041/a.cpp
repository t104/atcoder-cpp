#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (abs(b-a) % 2 == 0) {
        cout << (ll) abs(b-a)/2 << endl;
        return 0;
    }

    ll ans = min(a-1, n-b) + 1 + (b-a-1)/2;
    cout << ans << endl;
    return 0;
}