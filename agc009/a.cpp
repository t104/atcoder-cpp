#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a.at(i) >> b.at(i);
    ll ans = 0;
    for (int i = n-1; 0 <= i; --i) {
        a.at(i) += ans;
        if (a.at(i) % b.at(i) != 0) {
            ans += b.at(i) * (a.at(i) / b.at(i) + 1) - a.at(i);
        }
    }
    cout << ans << endl;
    return 0;
}