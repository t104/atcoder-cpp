#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x.at(i) >> y.at(i);

    vector<int> xplusy(n), xminusy(n);
    rep(i,n) {
        xplusy.at(i) = x.at(i) + y.at(i);
        xminusy.at(i) = x.at(i) - y.at(i);
    }
    sort(xplusy.begin(), xplusy.end());
    sort(xminusy.begin(), xminusy.end());
    ll ans = (ll) abs(xplusy.at(0) - xplusy.at(n-1));
    ans = max(ans, abs((ll) xminusy.at(0) - xminusy.at(n-1)));
    cout << ans << endl;
    return 0;
}