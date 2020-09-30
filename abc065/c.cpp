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
    int n, m;
    cin >> n >> m;
    int d = abs(n-m);
    mint ans = 1;
    if (1 < d) {
        cout << 0 << endl;
        return 0;
    }
    if (d <= 1) {
        for (int i = 1; i <= n; ++i) ans *= i;
        for (int i = 1; i <= m; ++i) ans *= i;
    }
    if (d == 0) ans *= 2;

    cout << ans.val() << endl;
    return 0;
}