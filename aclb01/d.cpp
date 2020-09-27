#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

const int MAX_A = 300005;

int op(int a, int b) { return max(a, b);}
int e() { return 0;}

template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    segtree<int, op, e> dp(MAX_A);
    rep(i,n) {
        int x = a.at(i);
        int l = max(0, x-k);
        int r = x + k + 1;
        int now = dp.prod(l, r) + 1;
        dp.set(x, max(dp.get(x), now));
    }
    int ans = dp.all_prod();
    cout << ans << endl;
    return 0;
}