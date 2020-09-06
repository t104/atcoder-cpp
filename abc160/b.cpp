#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll x;
    cin >> x;
    ll ans = 0;
    ans += (x/500) *1000;
    ans += ((x%500) /5) *5;
    cout << ans << endl;
    return 0;
}