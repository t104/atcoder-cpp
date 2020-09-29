#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> s(n);
    rep(i,n) cin >> a.at(i);
    s.at(0) = a.at(0);
    for (int i = 1; i < n; ++i) s.at(i) = a.at(i) + s.at(i-1);
    ll ans = 1e15;
    rep(i, n-1) ans = min(ans, abs(s.at(n-1) - s.at(i) - s.at(i)));
    cout << ans << endl;
    return 0;
}