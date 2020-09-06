#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll h, w;
    cin >> h >> w;
    ll ans = (h * w + 1)/2;
    if(h == 1 || w == 1) {
        cout << 1 << endl;
    }
    else cout << ans << endl;
    return 0;
}
