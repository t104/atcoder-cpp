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
    vector<int> a(n), b(n);
    rep(i,n) cin >> a.at(i);
    rep(i,n) cin >> b.at(i);
    vector<int> d(n);
    rep(i,n) d.at(i) = a.at(i) - b.at(i);
    sort(d.begin(), d.end());
    ll sum = 0;
    int ans = 0;
    rep(i,n) {
        if (d.at(i) < 0) {
            sum += d.at(i);
            ans++;
        }
        else break;
    }
    if (ans == 0) {
        cout << ans << endl;
        return 0;
    }
    for (int i = n-1; 0 <= i; --i) {
        sum += d.at(i);
        ans++;
        if (0 <= sum) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}