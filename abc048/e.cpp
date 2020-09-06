#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll n, ans = 0;;
    cin >> n;

    if((n%2) != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll q = 5;
    while(q <= n) {
        ans += n/(2*q);
        q *= 5;
    }
    cout << ans << endl;
    return 0;
}