#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    if (n%2 == 0) {
        map<int, int> mp;
        rep(i,n) mp[a.at(i)]++;
        for (auto m : mp) {
            if (m.second % 2 == 1) {
                cout << "First" << endl;
                return;
            }
        }
        cout << "Second" << endl;
    }
    else {
        cout << "Second" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    rep(i,t) solve();
    return 0;
}