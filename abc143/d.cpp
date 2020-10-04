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
    vector<int> l(n);
    rep(i,n) cin >> l.at(i);
    sort(l.begin(), l.end());
    ll ans = 0;
    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                int ab = l.at(i) + l.at(j);
                int bc = l.at(j) + l.at(k);
                int ca = l.at(k) + l.at(i);
                if (l.at(i) < bc && l.at(j) < ca && l.at(k) < ab) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}