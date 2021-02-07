#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ld = long double;

int main(){
    ld X, Y, R;
    cin >> X >> Y >> R;
    R = nextafter(R, INFINITY);
    ll ans = 0;
    const ll from = ceil(X - R), to = floor(X + R);
    for(ll x = from; x <= to; x++){
        const ld d = sqrt(R * R - (X - x) * (X - x));
        const ll from = ceil(Y - d), to = floor(Y + d);
        ans += to - from + 1;
    }
    cout << ans << endl;
}