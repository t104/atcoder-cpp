#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n, m;
    cin >> n >> m;
    
    ll ans = 0;
    
    if (m < 2*n) {
        ans += m/2;
        cout << ans << endl;
        return 0;
    }

    if (2*n <= m) {
        ans += n;
        m -= 2*n;
        n = 0;
    }
    ans += m/4;
    cout << ans << endl;
    return 0;
}