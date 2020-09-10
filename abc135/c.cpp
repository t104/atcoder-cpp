#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1), b(n);
    rep(i,n+1) cin >> a.at(i);
    rep(i,n) cin >> b.at(i);

    ll ans = 0;
    rep(i,n) {
        int x = min(a.at(i), b.at(i));
        ans += x;
        b.at(i) -= x;
        int y = min(a.at(i+1), b.at(i));
        ans += y;
        a.at(i+1) -= y;
    }
    cout << ans << endl;
    return 0;
}