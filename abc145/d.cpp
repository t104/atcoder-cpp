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
    mint x = 1, y = 1;
    rep(i,r) x *= n - i;
    for (int i = 1; i <= r; ++i) y *= i;
    return x * y.pow(mod-2);
}

int main() {
    int x, y;
    cin >> x >> y;
    int ansx = -1, ansy = -1;
    for (int xi = 0; xi <= x && 2*xi <= y; ++xi) {
        int yi = y - 2*xi;
        if (xi + 2*yi != x) continue;
        ansx = xi;
        ansy = yi;
        break;
    }
    if (ansx == -1) cout << 0 << endl;
    else cout << choose(ansx+ansy, ansx).val() << endl;
    return 0;
}