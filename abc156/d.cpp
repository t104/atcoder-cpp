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
const int mod = 1000000007;

mint choose (int n, int r) {
    mint x = 1;
    rep(i, r) x *= n - i;
    mint y = 1;
    for (int i = 1; i <= r; ++i) y *= i;
    return x * y.pow(mod-2);
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    mint ans = ((mint) 2).pow(n);
    ans--;
    ans -= choose(n, a);
    ans -= choose(n, b);
    cout << ans.val() << endl;
    return 0;
}