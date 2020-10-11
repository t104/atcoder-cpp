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
    map<P,int> mp;
    int q = 1;
    for (int i = 1; i <= n; ++i) {
        int end = i%10;
        if (10 <= i/q) q *= 10;
        int front = i/q;
        mp[{front, end}]++;
    }
    ll ans = 0;
    for (auto m : mp) {
        P rev = {m.first.second, m.first.first};
        if (mp.count(rev)) {
            ans += (ll) mp.at(rev) * m.second;
        }
    }
    cout << ans << endl;
    return 0;
}