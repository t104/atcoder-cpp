#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    ll sum = 0;
    rep(i,n) {
        sum += a.at(i);
        sum %= MOD; 
    }
    ll ans = 0;
    rep(i,n) {
        sum -= a.at(i);
        while (sum < 0) sum += MOD;
        ans += (ll) sum * a.at(i);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}