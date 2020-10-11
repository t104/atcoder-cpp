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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a.at(i);
    rep(i,n) cin >> b.at(i);
    ll plus = 0, minus = 0;
    rep(i,n) {
        int d = a.at(i) - b.at(i);
        if (0 <= d) minus += d;
        else plus -= (d-1)/2;
    }
    if (minus <= plus) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}