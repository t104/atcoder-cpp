#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    rep(i,n) cin >> x.at(i);
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ll byA = (ll) a * (x.at(i) - x.at(i-1));
        ans += min(byA, (ll) b);
    }
    cout << ans << endl;
    return 0;
}