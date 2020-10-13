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
    vector<int> c(4);
    rep(i,4) cin >> c.at(i);
    int sum = 0;
    rep(i,4) sum += c.at(i);
    if (sum%2 == 1) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 1; i < (1<<4); ++i) {
        int s = 0;
        rep(j,4) {
            if ((i>>j)&1) s += c.at(j);
        }
        if (s == sum/2) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}