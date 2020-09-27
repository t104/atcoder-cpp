#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    dsu d(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        d.merge(a, b);
    }
    int ans = 0;
    rep(i, n) {
        if (d.same(0, i)) continue;
        d.merge(0, i);
        ans++;
    }
    cout << ans << endl;
    return 0;
}