#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;
const int max_n = 2e5 + 5;

ll comb(int n, int r) {
    if (r == 0 || r == n) return 1;
    else if (r == 1) return n;
    return comb(n-1, r-1) + comb(n-1, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    vector<ll> sum(n);
    sum.at(0) = a.at(0);
    for (int i = 1; i < n; ++i) sum.at(i) = sum.at(i-1) + a.at(i);
    map<ll, int> mp;
    rep(i,n) mp[sum.at(i)]++;
    ll ans = 0;
    if (mp.count(0)) ans += mp.at(0);
    for (auto m : mp) {
        if (m.second < 2) continue;
        ans += comb(m.second, 2);
    }
    cout << ans << endl;

    return 0;
}