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
    rep(i,n) cin >> a.at(i);
    int ans = 1e9;
    for (int x = -100; x <= 100; ++x) {
        int sum = 0;
        rep(i,n) sum += (a.at(i) - x) * (a.at(i) - x);
        chmin(ans, sum);
    }
    cout << ans << endl;
    return 0;
}