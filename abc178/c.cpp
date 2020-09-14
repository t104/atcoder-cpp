#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll ans = 1;
    rep(i,n) {
        ans *= 10;
        ans %= MOD;
    }
    ll nine = 1;
    rep(i,n) {
        nine *= 9;
        nine %= MOD;
    }

    ll eight = 1;
    rep(i,n) {
        eight *= 8;
        eight %= MOD;
    }

    rep(i,2) {
        ans += MOD;
        ans -= nine;
        ans %= MOD;
    }
    
    ans += eight;
    ans %= MOD;

    cout << ans << endl;
    return 0;
}