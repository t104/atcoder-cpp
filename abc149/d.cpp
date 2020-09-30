#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    map<char, int> mp = {{'r', p}, {'s', r}, {'p', s}};
    string t;
    cin >> t;
    ll ans = 0;
    rep(i,n) {
        int point = 0;
        if (0 <= i-k && t.at(i) == t.at(i-k)) {
            t.at(i) = 'x';
        }
        else point = mp.at(t.at(i));
        ans += point;
        // cout << point << endl;
    }
    cout << ans << endl;
    return 0;
}