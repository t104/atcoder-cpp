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

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (n < a+b) {
        cout << 0 << endl;
        return;
    }
    mint pa = (n-a+1);
    mint pb = (n-b+1);
    mint px1 = (n-a-b+2) * (n-a-b+1);
    mint px2 = pa*pb - px1;
    mint ans = pa.pow(2) * pb.pow(2) - px2.pow(2);
    cout << ans.val() << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i,t) solve();
    return 0;
}