#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
    ll q, h, s, d;
    ll n;
    cin >> q >> h >> s >> d >> n;
    n *= 4;
    vector<P> table = {{1, q}, {2, h}, {4, s}, {8, d}};
    sort(table.begin(), table.end(), [](P x, P y) {
        return (x.second * y.first) < (y.second * x.first);
    });

    ll ans = 0;
    rep(i, 4) {
        ll count = (ll) n / table.at(i).first;
        n -= (ll) count * table.at(i).first;
        ans += (ll) count * table.at(i).second;
    }
    cout << ans << endl;
    return 0;
}