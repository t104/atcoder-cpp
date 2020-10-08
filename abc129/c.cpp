#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;
using mint = modint1000000007;

int main() {
    int n,m;
    cin >> n >> m;
    set<int> a;
    rep(i,m) {
        int ai;
        cin >> ai;
        a.insert(ai);
    }
    mint ans = 1;
    vector<mint> dp(n+1);
    dp.at(0) = 1;
    for (int i = 1; i < n+1; ++i) {
        if (!a.count(i)) {
            dp.at(i) += dp.at(i-1);
            if (0 <= i-2) dp.at(i) += dp.at(i-2);
        }
    }
    cout << dp.at(n).val() << endl;
    return 0;
}