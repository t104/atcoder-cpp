#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;

vector<ll> enum_divisors(ll n) {
    vector<ll> res;
    for (ll i = 1; i*i <= n; ++i) {
        if (n%i == 0) {
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    vector<ll> divisors = enum_divisors(n);
    for (ll d : divisors) {
        ll q = n/d - 1;
        if (0 < q && n%q == n/q) ans += q;
    }
    cout << ans << endl;
    return 0;
}