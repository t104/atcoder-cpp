#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    int n;
    cin >> n;
    vector<ll> t(n);
    rep(i,n) cin >> t.at(i);
    ll ans = t.at(0);
    for (int i = 1; i < n; ++i) ans = lcm(ans, t.at(i));
    cout << ans << endl;
    return 0;
}