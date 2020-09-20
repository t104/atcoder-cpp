#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> r;
    set<ll> s;
    r.push_back(x);
    s.insert(x);
    for (ll i = 1; i <= n; ++i) {
        x *= x;
        x %= m;
        if (s.count(x)) {
            break;
        }
        r.push_back(x);
        s.insert(x);
    }

    int len = r.size();
    int start = 0;
    rep(i, len) if (r.at(i) == x) start = i;
    ll sum = 0, ans = 0;

    rep(i, len) sum += r.at(i);

    rep(i, start) {
        sum -= r.at(i);
        ans += r.at(i);
    }
    n -= start;
    len -= start;
    ans += sum * ((ll) n / len);
    rep(i, n % len) ans += r.at(start + i);
    cout << ans << endl;
    return 0;
}